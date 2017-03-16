import sys, math

infile = sys.stdin

T = int(infile.readline())

for case_num in xrange(1, T+1):
    C, F, X = [float(v) for v in infile.readline().split()]
    n = math.ceil((F * X - 2.0 * C  - F * C) / (F * C))
    n = int(n)
    ret = -9
    if n <= 0:
        ret = X / 2.0
    else:
        ret = X / (2.0 + F * n)
        for i in xrange(n):
            ret += C / (2.0 + i * F)

    print "Case #%d: %.7f" % (case_num, ret)
