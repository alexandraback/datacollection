# a backup solution in python if SQL times out :)
from sys import stdin
T = int(stdin.readline())
for t in range(T):
    got = set()
    A, B = [ int(x) for x in stdin.readline().split() ]
    for x in range(A,B+1):
        sx = str(x)
        sxx = sx+sx
        for i in range(1,len(sx)):
            sy = sxx[i:i+len(sx)]
            y = int(sy)
            if x < y <= B: got.add((x,y))
    print "Case #%d: %d" % (t+1,len(got))
