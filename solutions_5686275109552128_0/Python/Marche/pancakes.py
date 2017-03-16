#!/usr/bin/python3

import sys

DEBUG = False
def debug(s):
    if DEBUG: print(s)
    else: pass
            
if __name__ == '__main__':
    with open(sys.argv[1], 'r') as f:
        T = int(f.readline())
        for test in range(1, T+1):
            D = int(f.readline())
            plates = list(map(int, f.readline().split()))
            m = max(plates)
            best_time = m
            for i in range(1, m+1):
                special = 0
                for p in plates:
                    quot, rem = divmod(p, i)
                    special += quot if rem else quot-1
                    debug("i = {}, special = {}, (quot,rem) = {}, p = {}".format(i, special, (quot,rem), p))
                time = special + i
                if time < best_time:
                    best_time = time
            print("Case #{}: {}".format(test, best_time))
