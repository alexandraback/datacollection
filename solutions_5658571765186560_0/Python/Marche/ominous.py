#!/usr/bin/python

import sys

DEBUG = False
def debug(s):
    if DEBUG: print(s)
    else: pass
            
if __name__ == '__main__':
    with open(sys.argv[1], 'r') as f:
        T = int(f.readline())
        for test in range(1, T+1):
            X, R, C = map(int, f.readline().split())
            if X == 1:
                result = "GABRIEL"
            elif X == 2:
                result = "GABRIEL" if R*C % 2 == 0 else "RICHARD"
            elif X == 3:
                result = "RICHARD" if min(R,C) == 1 or R*C % 3 != 0 else "GABRIEL"
            elif X == 4:
                result = "RICHARD" if min(R,C) <= 2 or R*C % 4 != 0 else "GABRIEL"
            elif X == 5:
                result = "RICHARD" if min(R,C) <= 3 or R*C % 5 != 0 else "GABRIEL"
            elif X == 6:
                result = "RICHARD" if min(R,C) <= 3 or R*C % 6 != 0 else "GABRIEL"
            else:
                result = "RICHARD"

            print("Case #{}: {}".format(test, result))
