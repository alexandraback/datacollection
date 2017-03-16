#!/usr/bin/python3

import sys

DEBUG = True
def debug(*s):
    if DEBUG:
        print(*s, file=sys.stderr)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T+1):
        S = input()
        result = S[0]
        for i in range(1, len(S)):
            if S[i] >= result[0]:
                result = S[i] + result
            else:
                result = result + S[i]


        print("Case #{}: {}".format(case, result))
        print("Case #{}: {}".format(case, result), file=sys.stderr)
