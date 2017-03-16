#!/usr/bin/env python3

# (C) 2014 Susanne Oberhauser-Hirschoff
# The MIT License applies: http://opensource.org/licenses/MIT

# Google codejam 2014
# Problem C. Minesweeper Master

from codejam_2014 import *

class XX: pass
class Codejam_2014_C(Codejam_2014):
    def __init__(self):
        Codejam_2014.__init__(self, '\n')
    def parse_one_problem_set(self):
        problem = XX()
        # r: n_rows
        # c: n_columns
        # m: n_mines
        problem.r, problem.c, problem.m = [int(x) for x in self.file.readline().split()]
        #print(problem.__dict__)
        return problem

    def solve_problem(self, problem):
        # If just one field is free, the click must be on that field.

        # If several fields are free, then the field clicked on must not touch
        # any mines, so the recursion rule kicks in and 'flood fills' the
        # unmined area.

        # for factually unidimensional fields (r == 1 or c == 1), this works
        # for any number of free fields, starting at the 'corner', i.e. one
        # end of the unidemensional mine field.

        # for truely two-dimensional fields (r > 1 and c > 1), the smallest
        # possible area for this is a 2x2 corner, like this:
        # 
        #   c.***
        #   ..***
        #   *****
        #   *****
        #
        # by pure enumeration, you'll see that for 3 or less free fields,
        # there is no solution for r,c>1 --- there'll always be one mine
        # adjacent to the clicked-on field.
        #
        # Likewise for 5 and for 7 fields, you can see that there's going to
        # be a single-field 'antenna', where the 'flood-fill' can't crawl
        # into.
        #
        #   c.***  # no matter where you put an empty field adjacent to the
        #   ..***  # empty area, the border of the empty field already touches
        #   *****  # a mine and thus won't recurse.
        #   *****
        #
        #   c..**  # likewise!
        #   ...**
        #   *****
        #   *****
        #
        # if r == 2 or c == 2, any odd number will have an 'antenna'.
        #
        # if both r>2 and c>2, any number of free cells >= 8 can be flood
        # filled.
        # 8 = 3+3+2
        # 9 = 3x3 which is safe.
        # 11 = 3x3+2, which is also safe.
        #
        # soo...

        # To simplify the solution, we'll ensure c<=r by swapping if needed.
        # Then we generate a solution with the upper left corner filled.
        # If we had to swap, we'll simply transpose the solution...

        swapped = problem.r < problem.c

        if swapped:
            n_rows, n_columns = problem.c, problem.r
        else:
            n_columns, n_rows = problem.c, problem.r

        assert(n_rows >= n_columns)

        n_fields = n_rows * n_columns
        n_mines  = problem.m
        n_free   = n_fields - n_mines

        # only fill in free and mines, add click later
        free  = ['.']
        mine  = ['*']

        if n_free == 1:
            # always solvable, click on the free field
            rows = [free + mine * (n_columns - 1)] + [mine * n_columns] * (n_rows - 1)
        elif n_columns == 1:
            # allways solvable:
            rows = [free] * n_free + [mine] * n_mines
        elif n_free in [2, 3, 5, 7]: 
            # for more than 1 column there is no solution for these!
            return None
        elif n_columns == 2:
            # for two columns, an odd number of free fields > 1 can't be won
            # with one click
            if n_free % 2 == 1:
                return None
            # an even number of free fields in two columns always wins
            free_rows = n_free // 2
            rows = [free * 2] * (n_free // 2 ) + [mine * 2] * (n_mines // 2)
        else:
            # Three or more columns.  At least as many rows.
            #
            # We'll create a rectangular block of free fields in the top two
            # or more rows (n_top_free_rows, top_free__columns).
            # This is followed by one shorter row of at least two free fields
            # (last_free_row__columns)
            # 
            # obviously this won't always add up so the second to last and in
            # a corner case (only two full rows before) the third to last row
            # will be one shorter than top_free__columns.  So we may need grab
            # free fields from n_steal_last rows.
            #

            # Use less columns if there is not enough free fields for two full
            # rows:
            if n_free < 2 * n_columns:
                top_free__columns = n_free // 2
            else:
                top_free__columns = n_columns

            n_top_free_rows, remainder = divmod(n_free, top_free__columns)

            if remainder == 0:
                assert(n_top_free_rows >= 2)
                rows =  [free *  top_free__columns  + mine * (n_columns - top_free__columns )] * n_top_free_rows
                rows += [mine * n_columns ] * (n_rows - n_top_free_rows )
                
            else:
                if remainder == 1:
                    # need to 'borrow' one or two free fields from the
                    # previous one or two rows
                    if n_top_free_rows == 2:
                        n_steal_last = 2
                    else:
                        n_steal_last = 1
                else:
                    n_steal_last = 0

                rows =  [free *  top_free__columns         + mine * (n_columns - top_free__columns       )] * ( n_top_free_rows - n_steal_last)
                rows += [free * (top_free__columns -1 )    + mine * (n_columns - top_free__columns + 1   )] *  n_steal_last
                rows += [free * (remainder + n_steal_last) + mine * (n_columns - remainder - n_steal_last)] 
                rows += [mine * n_columns ] * (n_rows - n_top_free_rows - 1)

            if len(rows) != n_rows:
                print(rows)
                print(n_rows)
                print(n_free)
                print(n_columns)
                print(n_top_free_rows)
                print(remainder)
                print(n_steal_last)
                raise
            assert(len(rows) == n_rows)
        # always click in the upper left corner

        # nota bene:  this pig wont fly as row[0][0] usually is a clone to some [free] item.
        # WRONG: row[0][0] = 'c'
        # we dereference that by copying the items while transposing them:
        if swapped:
            # transpose the solution
            solution = [list(column_is_row) for column_is_row in zip(*rows)]
        else:
            solution = [list(row)           for row in rows]

        # now they are individual items...
        solution[0][0] = 'c'

        return solution

    def str_solution(self, solution):
        if solution is None:
            return "Impossible"
        else:
            return '\n'.join(''.join(row) for row in solution)
            

if __name__ == "__main__":
    import sys
    a = Codejam_2014_C()
    a.run(sys.argv[1])
