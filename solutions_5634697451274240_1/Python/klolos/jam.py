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
    cake = readline()
    flips = 0
    for i in range(len(cake) - 1):
        if cake[i] != cake[i+1]:
            flips += 1
    printres(flips if cake[-1] == '+' else flips + 1)

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

