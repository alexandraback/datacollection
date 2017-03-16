#!/usr/bin/env python
import sys

case_num = 1
def printres(result):
    global case_num
    print "Case #%s: %s" % (case_num, result)
    case_num += 1

def readline(): 
    return sys.stdin.readline().rstrip('\n')
def splitline(f):
    return map(f, readline().split())


def position(p, K, C):
    pos = p
    for i in range(C - 1):
        pos = pos * K + min(p + i + 1, K - 1)

    return pos


def solve():
    K, C, S = splitline(int)
    if K > S * C:
        printres('IMPOSSIBLE')
        return

    pos = []
    for i in range(S):
        if C * i < K:
            pos.append(position(C * i, K, C))

    printres(' '.join([str(p + 1) for p in pos]))


def main():
    for i in range(int(readline())): solve()


if __name__ == '__main__': 
    main()

