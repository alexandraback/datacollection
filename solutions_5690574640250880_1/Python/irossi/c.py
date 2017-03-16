'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
import os
import itertools


if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)
    sys.argv.remove("--debug")

def main():
    problem_input = sys.stdin
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
        if os.path.isfile(input_file):
            problem_input = open(input_file)
        
    cases = int(problem_input.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case(problem_input)
        print "Case #%s:%s" % (case + 1, resp,)

def _make_minefield(rows, columns, content='.'):
    return [[content for _x in xrange(columns)] for _y in xrange(rows)]

def _print_minefield(minefield, swapped):
    if swapped:
        rows = len(minefield[0])
        columns = len(minefield)
        real_mf = _make_minefield(rows, columns)
        for r in xrange(rows):
            for c in xrange(columns):
                real_mf[r][c] = minefield[c][r]
        minefield = real_mf
        
    return "\n".join("".join(x) for x in minefield)

def run_case(problem_input):
    res = _solve(problem_input)
    return "\n" + res

def _solve(problem_input):
    rows, columns, mines = (int(x) for x in problem_input.readline().split())
    if rows == 1 and columns == 1:
        return "c"
    
    swapped = False
    if columns < rows:  # Ensure rows <= columns
        rows, columns = columns, rows
        swapped = True
    
    if rows == 1:
        free = columns - mines - 1
        row = ["c"] + ["."] * free + ["*"] * mines
        minefield = [row]
    else:
        minefield = _make_minefield(rows, columns, content='*')
        non_mines = rows * columns - mines
        if non_mines == 1:
            minefield[0][0] = 'c'
        elif rows == 2:
            if mines % 2 == 1 or non_mines == 2:
                return "Impossible"
            else:
                for x in xrange(non_mines / 2):
                    minefield[0][x] = minefield[1][x] = '.'
                
        elif non_mines < 4 or non_mines == 5 or non_mines == 7:
            return "Impossible"
        elif non_mines in [4, 6, 8]:
            coords = itertools.product(range(3), range(3))
            coords = sorted(coords, key=lambda (x, y): (max(x, y), x, y))[:non_mines]
            for r, c in coords:
                minefield[r][c] = "."
        elif mines == 0:
            minefield = _make_minefield(rows, columns)
        else:
            # 3 <= rows <= columns
            for rows_used in xrange(3, rows + 1):
                cols_used = int(non_mines / rows_used)
                logging.debug("Test:rows_used=%s,cols_used=%s", rows_used, cols_used)
                if  3 <= cols_used < columns:
                    break
            else:
                raise ValueError("%s not found for (%s,%s)" % (non_mines, rows, columns))
            # 
            logging.debug("rows_used=%s,cols_used=%s", rows_used, cols_used)
            
            for idx in xrange(non_mines):
                c, r = divmod(idx, rows_used)
                logging.debug("Freeing (%s,%s)", r, c)
                minefield[r][c] = '.'
                
            if non_mines % rows_used == 1:
                # Chot case
                minefield[r + 1][c] = '.'
                minefield[rows_used - 1][c - 1] = '*'
            
                
                 
                
#             free = rows * columns - mines
#             if free >= 2 * columns:
#                 placed_mines = rows * columns  
#                 for r in xrange(rows):
#                     for c in xrange(columns):
#                         if placed_mines == mines:
#                             continue
#                         minefield[r][c] = '.'
#                         placed_mines -= 1
#             else:
#                 col_num, remainder = divmod(free, 2)
#                 for r in xrange(2):
#                     for c in xrange(col_num):
#                         minefield[r][c] = '.'
#                 if remainder:
#                     # cant have remainder and rows < 3
#                     minefield[2][col_num] = '.'
                        
        minefield[0][0] = 'c'
    res = _print_minefield(minefield, swapped)
    if res.count("*") != mines:
        print mines, res.count("*")
        print res
        raise Exception("WTF!")
    return res

if __name__ == "__main__":
    main()
