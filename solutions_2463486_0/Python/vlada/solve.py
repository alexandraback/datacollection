#!/usr/bin/python

import math
import sys

# -------------------------------------------------------------------------------------------------

def all_value(it, values):
    return all( ( x in values for x in it ) )

def any_value(it, values):
    return any( ( x in values for x in it ) )

# -------------------------------------------------------------------------------------------------

def ispal(n):
    s = str(n)
    return s == s[::-1]

def dlist2int(d):
    assert(all_value(d, range(10)))
    assert(d[0] != 0)

    return int("".join(map(str, d)))

def next_pal(n):
    if ispal(n): return n
    #print "--- %s" % (n,)

    s = map(int, list(str(n)))
    s0 = s
    l = len(s)

    for i in xrange(l/2):
        j = l-i-1
        if s[i] == s[j]: continue
        if s[i] > s[j]: 
            s[j] = s[i]
            continue

        assert(s[j] > s[i])

        if s[j-1] < 9: 
            s[j-1] += 1
            s[j] = s[i]
            continue

        for jj in xrange(j, l): s0[jj] = 9
        return next_pal(dlist2int(s0) + 1)

    return dlist2int(s)
        
# -------------------------------------------------------------------------------------------------

def solve(a, b):
    ra = int(math.sqrt(a))
    rb = int(math.sqrt(b)) + 1

    #print "%s, %s" % (ra, rb)

    cnt = 0
    i = ra
    while i<=rb:
        if ispal(i):
            s = i*i
            #print " --- %d, %s, %s" % (i, s, ispal(s))
            if s>b: break
            if s>=a and ispal(s): 
                #print s
                cnt += 1

        i = next_pal(i+1)

    return cnt

# -------------------------------------------------------------------------------------------------

if 0:
    i = 1
    while i<1000:
        if ispal(i): print i
        i = next_pal(i+1)

#solve(1, 999)

# -------------------------------------------------------------------------------------------------

fin = open(sys.argv[1], "r")
fout = open("out.txt", "w")

n = int(fin.readline())

for i in range(n):
    a,b = map(int, fin.readline().strip().split())
    s = solve(a, b)
    fout.write("Case #%d: %d\n" % (i+1, s))













    

