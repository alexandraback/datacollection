#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        C, D, V = map(int, input().split())
        den = list(map(int, input().split()))
        
        max_feasible = 0
        original = den[:]
        added = []
        while max_feasible < V:
            max_feasible = 0
            for d in den:
                if d <= max_feasible + 1:
                    max_feasible += C*d
                else:
                    added.append(max_feasible + 1)
                    den = sorted(original + added)
                    debug(den)
                    break
            else:
                added.append(max_feasible + 1)
                den = sorted(original + added)

        result = len(added)

        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
