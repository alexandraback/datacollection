# -*- coding: utf-8 -*-

import logging
logger = logging.getLogger(__name__)

from Queue import Queue, Empty
from math import floor, ceil
from itertools import product

_INIT = None
_MINE = -6
_CLICK = -8
_POLLUTED = -17

def _remove_one(seed, col):
    """Takes one from seed folling the constraints.

    Returns c as the #Column that `one` is from
    """
    for c in range(len(seed)-1, -1, -1):
        if seed[c] >= 2:
            seed[c] -= 1
            return c
    raise Exception("Nothing to remove")

class Board(object):
    """
    Exposed functions should take R/C corresponding to the input, 
    while internal function (starts with _) can take internal ones (__R <= __C, transposed otherwise)
    """
    def __init__(self, R, C, M):
        """
        Notes: 
        - Don't check inputs, as those limits are described in the spec
        - Transposed so that __R >= __C internally
        """

        if R >= C:
            self.__transposed = False
            self.__R, self.__C = int(R), int(C)
        else:
            self.__transposed = True
            self.__R, self.__C = int(C), int(R)

        self.__M = int(M)
        self.reset()

        logger.info("Solving (R,C,M) = (%d, %d, %d)" % (self.R, self.C, self.M))

    @property
    def R(self): return self.__C if self.__transposed else self.__R

    @property
    def C(self): return self.__R if self.__transposed else self.__C

    @property
    def M(self): return self.__M

    def value_get(self, r, c):
        if self.__transposed:
            return self.__tbl[c][r]
        
        return self.__tbl[r][c]

    def value_set(self, r, c, value):
        if self.__transposed:
            self.__tbl[c][r] = value
            return
        
        self.__tbl[r][c] = value

    def reset(self, value = _INIT):
        self.__tbl = [
            ([value] * self.__C) for r in range(self.__R)
        ]

    def __str__(self):
        output = []

        for row in range(self.R):
            buff = []
            for col in range(self.C):
                x = self.value_get(row, col)
                buff.append("*" if x == _MINE else "c" if x == _CLICK else '.')

            output.append("".join(buff))
        return "\n".join(output)

    def header(self):
        return "(R:%d, C:%d, M:%d)" % (self.R, self.C, self.M)

    def solve(self):
        return self.__solve()

    def __solve(self):
        """
        Works on internal R/C defn
        """
        logger.debug("__R=%d, __C=%d" % (self.__R, self.__C))
        min_rows = int(ceil(float(self.M) / self.__R))
        logger.debug('Trying min_rows=%d' % min_rows)
        for row in range(min_rows, self.__R + 1):
            # iterate over Rows with mine presense
            for cond in self.__permutations(row):
                self.__apply_mines(cond)

                try:
                    if self.test():
                        return True
                except StopIteration as e:
                    logger.debug(e)
                    pass

        return False

    def __apply_mines(self, cond):
        self.reset(_INIT)
        logger.debug("Applying ")
        for row, mines in enumerate(cond):
            for col in range(mines):
                self.__tbl[row][col] = _MINE
        self.__tbl[-1][-1] = _CLICK

    def __series_ok(self, series):
        for p in range(len(series) - 1):
            if series[p] > series[p+1]: 
                return False

            if series[p] > self.__C:
                return False

        return True

    def __permutations(self, row_count):
        """
        Lists tuples on mine distributions on each row following constraints:
            1. mines[X] >= mines[Y] if X < Y
            2. mines[cols] != 0
        """

        # the rows for decrement
        for series in product(range(1,self.__C + 1), repeat = row_count):
            series = list(series)

            if not self.__series_ok(series):
                continue

            if sum(series) != self.__M: continue
            series.reverse()

            logger.debug("Permutator pops %s" % list(series))
            yield series

    def neighbors(self, r, c):
        for ro, co in self.neighbors_and_self(r, c):
            if ro == 0 and co == 0:
                continue
            yield (ro, co)

    def neighbors_and_self(self, r, c):
        roff, coff = set([0]), set([0])

        if r < 0 or c < 0 or r >= self.R or c >= self.C:
            raise IndexError("Index Out of Bounds")

        if r > 0: roff.add(-1)
        if r < self.R - 1: roff.add(1)
        if c > 0: coff.add(-1)
        if c < self.C - 1: coff.add(1)

        for ro in roff:
            for co in coff:
                yield (ro, co)

        raise StopIteration()

    def calc(self, r, c):
        mines = 0;
        for ro, co in self.neighbors_and_self(r, c):
            if self.value_get(r+ro, c+co) == _MINE:
                mines += 1
        return mines

    def test(self):
        if self.R * self.C - self.M == 1:
            # Pass the test automatically if there are all Mines but one
            return True

        mine_n = 0
        zero_n = 0
        click = None

        for r in range(self.R):
            for c in range(self.C):
                if self.value_get(r, c) == _INIT :
                    self.value_set(r, c, self.calc(r, c))
                    if self.value_get(r, c) == 0:
                        zero_n += 1
                elif self.value_get(r,c) == _MINE:
                    mine_n += 1
                else:
                    click = (r, c)

        if zero_n > 0 and self.calc(*click) != 0:
            raise Exception("Click on non-zero")

        if mine_n != self.M:
            raise Exception("Mine Missing")

        for r in range(self.R):
            for c in range(self.C):
                if self.value_get(r, c) != _MINE:
                    self._test_block(r, c)

        # test_continuity
        for r in range(self.R):
            for c in range(self.C):
                if self.value_get(r, c) == 0:
                    self._test_pollute(r, c)
                    break
            else:
                continue
            break

        for r in range(self.R):
            for c in range(self.C):
                if self.value_get(r, c) == 0:
                    raise StopIteration("Discontinuity")
                elif self.value_get(r, c) == _POLLUTED:
                    self.value_set(r, c, 0)

        return True

    def _test_pollute(self, r, c):
        self.value_set (r, c, _POLLUTED)
        for ro, co in self.neighbors_and_self(r, c):
            if self.value_get(r+ro, c+co) == 0:
                self._test_pollute(r+ro, c+co)

    def _test_block(self, r, c):
        """
        Every block should have 1+ neighbor or self marked 0, 
        except for the clicked one
        """
        if self.value_get(r, c) == _CLICK:
            return

        for ro, co in self.neighbors_and_self(r, c):
            val = self.value_get(r + ro, c + co)
            if val == 0:
                return
            elif val == _CLICK:
                if self.calc(r + ro, c + co) == 0: return

        raise StopIteration("Disconnected node found at %d, %d" % (r, c))
