import sys
import math

f = open(sys.argv[1])
n = int(f.readline())

for t in xrange(1,n+1):
    s = f.readline().strip("\n").split(" ")
    r = int(s[0])
    c = int(s[1])
    w = int(s[2])

    cb = math.floor(float(c)/float(w)) * r
    if c % w == 0:
        cb += w - 1
    else:
        cb += w
        
    print "Case #%d: %d" % (t,cb)


        










