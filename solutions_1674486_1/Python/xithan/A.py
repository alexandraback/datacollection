#!/usr/local/Cellar/python3/3.2.2/bin/python3


from numpy import matrix
from numpy import linalg



def solve(infile):
    n = int(infile.readline().strip())
    tm = []
    for i in xrange(n):
        l = [int(z) for z in infile.readline().split()]
        a = [0]*n
        for x in xrange(len(l)-1):
            a[l[x+1]-1] = 1
        

        
        tm.append(a)
    for i in xrange(n):
        tm[i][i] = -1
    
    A = matrix(tm)
    #print repr(A)
    A = A.I
    #print repr(A)
    res = "No"
    for x in xrange(n):
        for y in xrange(n):
            if A[x,y] < -1:
                res = "Yes"
                break
    return  res




infile = open("/Users/phi/Dropbox/CodeJam/Current/A-large-0.in", 'r')
t = int(infile.readline())
outfile = open("/Users/phi/Dropbox/CodeJam/Current/A-large-0.out", 'w')
for i in xrange(t):
    s = "Case #%d: %s\n" % (i+1,solve(infile))
    print s
    outfile.write(s)
outfile.close()
infile.close()
    

