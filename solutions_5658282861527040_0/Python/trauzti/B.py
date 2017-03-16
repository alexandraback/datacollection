import sys
getint = lambda: int(raw_input())
getfloats = lambda: [float(z) for z in raw_input().split()]
getints = lambda: [int(z) for z in raw_input().split()]



# bitwise AND of the two machine numbers
# machine1: non-negative less than A
# machine2: non-negative less than B
# Catalina buys all non-negative integers less than K


for t in xrange(1, 1+getint()):
    A,B,K = getints()
    count = 0
    for a in xrange(A):
        for b in xrange(B):
            res = a&b
            if res < K:
                count += 1


    print "Case #%d: %s" % (t, count)
