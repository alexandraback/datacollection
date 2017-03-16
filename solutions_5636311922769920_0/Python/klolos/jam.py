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
    K, _, _ = splitline(int)
    printres(' '.join([str(i + 1) for i in range(K)]))

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

