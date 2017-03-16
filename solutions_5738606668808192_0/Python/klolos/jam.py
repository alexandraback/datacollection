#!/usr/bin/env python

import sys
import random
import math


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
    printres('')
    L, num_res = splitline(int)
    r = 0
    form = "{0:0%sb}" % (L - 2)
    while r < num_res:
        n = '1%s1' % form.format(random.randint(1, int('1' * (L - 2), base=2)))
        fail = False
        res = []
        for b in range(2, 11):
            num = int(n, base=b)
            for m in range(2,1000):
                if num % m == 0:
                    res.append(str(m))
                    break

        if len(res) == 9:
            print ' '.join([n] + res)
            r += 1

def main():
    for i in range(int(readline())): solve()

if __name__ == '__main__': 
    main()

