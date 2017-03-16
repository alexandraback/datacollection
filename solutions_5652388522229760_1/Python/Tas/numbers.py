import sys


def test(n):
    ds = set()
    i = 0
    while len(ds) < 10:
        i += 1
        s = list(str(n*i))
        ds |= set(s)
        #print n*i,ds
        if (i > 1000):
            raise "slow"
    return n*i




N = int(raw_input())

for i in xrange(N):
    w = int(raw_input())
    print "Case #{0}:".format(i+1),
    print "INSOMNIA" if w==0 else test(w)