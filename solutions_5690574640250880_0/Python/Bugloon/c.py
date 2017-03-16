import sys
from itertools import product

def is_solvable(R, C, M, result):
    clear = { pos: False for pos in product(range(C), range(R)) }
    to_clear = [(0,0)]
    
    while to_clear:
        x,y = to_clear.pop()
        clear[(x,y)] = True
        adjacent = [pos for pos in (x,y+1),(x+1,y),(x+1,y+1) if pos in clear]
        if all(result[pos] == "." for pos in adjacent):
            to_clear.extend(adjacent)
                
    return all(clear[pos] or result[pos] == "*" for pos in clear) 

def print_grid(result, R, C):
    for row in xrange(R):
        print("".join(result[(col,row)] for col in xrange(C)))
    

if __name__ == "__main__":

    testcases = int(sys.stdin.readline())

    for case in range(1, testcases+1):

        R, C, M = map(int, sys.stdin.readline().split())

        result = { pos: '.' for pos in product(range(C), range(R)) }
        result[(0,0)] = 'c'

        r, c = R, C
        
        while M > 0:
            if r >= c:
                posns = [(col, r-1) for col in xrange(c-1,-1,-1)]
                r -= 1
                spaces = c
            else:
                posns = [(c-1, row) for row in xrange(r-1,-1,-1)]
                c -= 1
                spaces = r
        
            for pos in posns:
                if M == 0 or (M == 1 and spaces == 2 and min(c,r) >= 3):
                    break
                result[pos] = "*"
                M -= 1
                spaces -= 1

        print("Case #{}:".format(case))

        if is_solvable(R, C, M, result):
            print_grid(result, R, C)
        else:
            print("Impossible")
        
        



