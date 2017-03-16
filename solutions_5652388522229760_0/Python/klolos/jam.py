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
    N = int(readline())
    if N == 0:
        printres('INSOMNIA')
        return

    digits = {}
    for i in range(100):
        n = str((i + 1) * N)
        for d in n:
            digits[d] = None
        if len(digits) == 10:
            printres(n)
            return

def main():
    for i in range(int(readline())):
        solve()

if __name__ == '__main__': 
    main()
