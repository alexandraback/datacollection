#!/usr/bin/python

import sys
from copy import deepcopy

EMPTY = '.'
MINE = '*'
CLICKED = 'c'

def transpose(field):
    z = [list(i) for i in zip(*field)]
    return z


def is_multiple(multiple, big_value):
    if big_value % multiple == 0:
        return True

def addmines(field, mines):
    field = deepcopy(field)
    bomb_placed = False
    full_line = False
    row = len(field)
    col = len(field[0])
    # if there are at least 2 empty cells at the same side of the col/row,
    # then we can add it
    # -2 because we need 2 empty cells at the bottom
    for ir in xrange(len(field) - 2):
        idx_start = -1
        idx_end = -1
        for ic in xrange(len(field[ir])):
            if field[ir][ic] == EMPTY and field[ir + 1][ic] == EMPTY and field[ir + 2][ic] == EMPTY:
                # ok for this one
                if idx_start == -1:
                    idx_start = ic
            else:
                # not good, stop the serie if it was started
                if idx_start != -1:
                    idx_end = ic - 1
                    break
        if idx_end == -1:
            # means we reached the end
            idx_end = col - 1
        if idx_start != -1 and idx_end != -1:
            # ok for this one?
            length = idx_end - idx_start + 1
            #print mines, length
            if mines < length:
                wished_end = idx_start + mines - 1
            else:
                full_line = True
                wished_end = idx_end
            if wished_end == col - 2:
                wished_end -= 1
            #print "adding mines from: field[%d][%d] to field[%d][%d]" % (ir, idx_start, ir, wished_end)
            for ic in xrange(idx_start, wished_end + 1):
                field[ir][ic] = MINE
            bomb_placed = wished_end - idx_start + 1
            mines -= bomb_placed
            break
    return field, mines, bomb_placed, full_line

def main():
    data = sys.stdin
    nb = int(data.readline())

    for icase in xrange(nb):
        global row, col
        row, col, mines = map(int, data.readline().split())
        field = []

        # special case with all mines
        if mines >= row * col:
            pass  # impossible
        elif mines == row * col - 1:
            for r in xrange(row):
                field.append([MINE]*col)
            field[row - 1][col - 1] = CLICKED
            mines = 0
        else:
            # create structure
            for r in xrange(row):
                field.append([EMPTY]*col)

            # algo 1 : fill lines/cols up to the last 2 row/cols
            while True:
                if mines == 0:
                    break
                to_use = 0
                field1, mines1, placed1, fl1 = addmines(field, mines)
                field2, mines2, placed2, fl2 = addmines(transpose(field), mines)
                #print "ONE", mines1, placed1, fl1, field1
                #print "TWO", mines2, placed2, fl2, field2
                if placed1 == 0 and placed2 == 0:
                    to_use = 0
                elif placed1 == 0:
                    to_use = 2
                elif placed2 == 0:
                    to_use = 1
                elif fl1 and fl2 or (not fl1 and not fl2):
                    # both full line, take the one that is a multiple
                    is_mult1 = is_multiple(placed1, mines)
                    is_mult2 = is_multiple(placed2, mines)
                    if is_mult1 and is_mult2 or (not is_mult1 and not is_mult2):
                        if placed1 > placed2:
                            to_use = 1
                        else:
                            to_use = 2
                    else:
                        if is_mult1:
                            to_use = 1
                        else:
                            to_use = 2
                elif fl1:
                    to_use = 1
                elif fl2:
                    to_use = 2
                else:
                    print "ERROR : ???"
                if to_use == 0:
                    break
                if to_use == 2:
                    field, mines = transpose(field2), mines2
                elif to_use == 1:
                    field, mines = field1, mines1
                else:
                    print "ERROR : SDHOULD NOT HAPPEND"

            done = False
            for ir in reversed(xrange(len(field))):
                for ic in reversed(xrange(len(field[ir]))):
                    if field[ir][ic] == EMPTY:
                        field[ir][ic] = CLICKED
                        done = True
                        break
                if done:
                    break

        possible = mines == 0
        print "Case #%d:\n%s" % (icase + 1, '\n'.join([''.join(f) for f in field]) if possible else "Impossible")



if __name__ == "__main__":
    main()
