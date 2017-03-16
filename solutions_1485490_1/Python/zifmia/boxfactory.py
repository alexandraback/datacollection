# google code jam 2012 round 1c

# box factory

import sys

memo = {}
def toys(acount, atype, bcount, btype):
    """toys() is the number of toys that the factory can produce
    using these assembly lines
    """

    """toys([],xx) = 0;  toys([], xx) = 0
    toys(ia,ib) = {
         if atype[ia] == btype[ib], min(acount[ia],bcount[ib]) +
             toys(ia+1,ib+1)
    """

    if len(acount)==0 or len(bcount)==0:
        return 0
    idx = (tuple(acount),tuple(bcount))
    if (idx) in memo:
        return memo[idx]
    # throw away both sets
    best = toys(acount[1:],atype[1:], btype[1:],bcount[1:])
    if atype[0]==btype[0]:
        score = min(acount[0],bcount[0])  # always use all matching toys
        if score== acount[0]:
            ac1 = acount[1:]
            at1 = atype[1:]
        else:
            ac1 = acount[:]
            ac1[0] -= score
            at1 = atype
        if score== bcount[0]:
            bc1 = bcount[1:]
            bt1 = btype[1:]
        else:
            bc1 = bcount[:]
            bc1[0] -= score
            bt1 = btype
        best = score + toys(ac1,at1,bc1,bt1)  # this is always better
    else:
        # ignore set a
        ac1 = acount[1:]
        at1 = atype[1:]
        score1 = toys(ac1,at1, bcount, btype)
        # ignore set b
        bc1 = bcount[1:]
        bt1 = btype[1:]
        score2 = toys(acount,atype, bc1,bt1)
        best = max(best, score1, score2)

    memo[idx] = best
    return best
    
"""
do i need to worry if two successive batches are identical????
"""

sys.setrecursionlimit(1000)

f = open("c:\\users\\James\\Downloads\\C-large.in", "r")
#f = open("boxfactory.in","r")
fout= open("boxfactory.out", "w")

t = int(f.readline())

for t1 in xrange(t):
    n,m = map(int, f.readline().split())
    
    line =map(int, f.readline().split())
    acount = [line[2*i] for i in range(n)]
    atype = [line[2*i+1] for i in range(n)]

    line =map(int, f.readline().split())
    bcount = [line[2*i] for i in range(m)]
    btype = [line[2*i+1] for i in range(m)]

    """ just in case"""
    for i in range(m-2,-1,-1):
        if btype[i]==btype[i+1]:
            #print "**"
            btype = btype[:i] + btype[i+1:]
            bcount = bcount[:i] + [ bcount[i]+bcount[i+1] ] + bcount[i+2:]

    for i in range(n-2,-1,-1):
        if atype[i]==atype[i+1]:
            #print "**"
            atype = atype[:i] + atype[i+1:]
            acount = acount[:i] + [ acount[i]+acount[i+1] ] + acount[i+2:]

    #print acount,atype
    #print bcount, btype
    #print len(acount)==len(atype)
    #print len(bcount)==len(btype)
        
    ntoys = toys(acount, atype, bcount, btype)
        
    answer = "Case #%d: %d\n" % (t1+1, ntoys)
        
    print answer,        
    fout.write( answer )
fout.close()
        
