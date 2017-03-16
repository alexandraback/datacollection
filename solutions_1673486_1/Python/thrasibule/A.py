import sys
fh = open(sys.argv[1])
T = int(fh.readline())
for i in xrange(T):
    [A, B] = map(int, fh.readline().split())
    p = map(float, fh.readline().split())
    exp = B + 2
    r = 1
    for j in xrange(A):
        r *= p[j]
        exp = min(exp, r*(B-A+2*(A-1-j)+1)+(1-r) * (B-A+2*(A-1-j)+B+1+1))
    print "Case #{0}: {1}".format(i+1,exp)
fh.close()
