#!/usr/bin/env python

ALOT = 10**15

def split_input(f=int):
    return [f(x) for x in raw_input().split()]

def solve(i,motes,sz,mx):
    if i >= len(motes):
        #print "fin"
        return 0
    next_mote = motes[i]
    #print i, sz, next_mote
    if sz > next_mote:
        #print "ok"
        return solve(i+1,motes,sz+next_mote,mx)
    else:
        #print "arf"
        #if remove
        a = len(motes) - i
        # add
        b = 0
        while sz <= next_mote:
            sz += sz-1
            b += 1
        sz += next_mote
        #print b
        if b >= mx:
            return None
        if b>=a:
            return a
        r = solve(i+1,motes,sz,a-b)
        if r is None:
            #print "r none"
            if a >= mx:
                return None
            else:
                return a
        else:
            #print "r ok",r,b
            return r+b
    

runs = input()
for run in xrange(1,runs+1):
    A,N = split_input()
    motes = split_input()
    assert len(motes) == N
    motes.sort()
    
    #print A,N, motes
    
    if A==1:
        print "Case #%d: %d" % (run, len(motes))
    else:
        #print "Case #%d: %d" % (run, solve(0,motes,A,ALOT))
        sz = A
        to_eat = [0]*N
        for i in xrange(N):
            a = 0
            while sz <= motes[i]:
                sz += sz - 1
                a += 1
            sz += motes[i]
            if i == 0:
                to_eat[i] = a
            else:
                to_eat[i] = to_eat[i-1] + a
        #print to_eat
        mn = min(to_eat[-1],N)
        for i in xrange(1,N):
            mn = min(mn,to_eat[i-1] + N-i)
        print "Case #%d: %d" % (run, mn)
