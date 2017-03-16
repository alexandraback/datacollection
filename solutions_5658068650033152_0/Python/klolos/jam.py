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


def solve():
    N, M, K = splitline(int)
    if K < 5 or N < 3 or M < 3:
        printres(K)
        return
    if K == 5:
        printres(4)
        return
    if N < M:
        N, M = M, N
    big = small = 3
    blocks = 4
    num = 5
    while big < M - 1:
        if num >= K-(big-1)/2:
            printres(blocks+1)
            return
        big += 1
        blocks += 2
        num += small
        if num >= K:
            printres(blocks)
            return
        if num >= K-(big-1)/2:
            printres(blocks+1)
            return
        small += 2
        big += 1
        blocks += 2
        num += big
        if num >= K:
            printres(blocks)
            return
        if num >= K-(big-1)/2:
            printres(blocks+1)
            return

    if small < M:
        if num >= K-(small-1)/2:
            printres(blocks+1)
            return
        small += 1
        num += big
        blocks += 2
        if num >= K:
            printres(blocks)
            return
        if num >= K-(small-1)/2:
            printres(blocks+1)
            return

    while big < N:
        if num >= K-(small-1)/2:
            printres(blocks+1)
            return
        big += 1
        num += small
        blocks += 2
        if num >= K:
            printres(blocks)
            return
        if num >= K-(small-1)/2:
            printres(blocks+1)
            return
    
    side = (small-1)/2
    while side > 0:
        for i in range(4):
            num += side
            blocks += 1
            if num >= K:
                printres(blocks)
                return
        side -= 1


def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

