#!/usr/bin/env python

from sys import stdin, stderr

def p2(i):
    ret = ''
    while i >= 2:
        ret += str(i % 2)
        i /= 2
        pass
    ret += str(i % 2)
    return ret[::-1]

def check(s):
    ret = 0
    for i, c in enumerate(s):
        if c == '0': continue
        ret += 1
        if i % 2 == 0: ret -= 2
        pass
    return ret == 0


for T in range(int(stdin.readline())):
    wds = stdin.readline().split()
    N = int(wds[0])
    J = int(wds[1])

    val = 2**(N-1) + 1
    while val % 3 != 0: val += 2

    print 'Case #%d:' % (T+1)

    for j in range(J):
        val += 6
        s = p2(val)
        while not check(s):
            val += 6
            s = p2(val)
            pass

        print s,
        for p in range(3, 12): print p,
        #for p in range(3, 12): print float(int(s, p-1)) / p,
        print
    
