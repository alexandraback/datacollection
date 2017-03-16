import math

def gcd(a,b):
    while b != 0:
        r = a % b;
        a = b;
        b = r;

    return a;

with open('A-small-attempt0.in') as f:
    T = int(f.readline())

    for case in xrange(T):
        data = [int(x) for x in f.readline().split("/")]
        P = data[0]; Q = data[1]

        r = gcd(P,Q)
        P /= r; Q /= r;
        if 2**math.floor(math.log(Q)/math.log(2)) != Q:
            print "Case #%d: impossible" % (case+1)
            continue

        t = 1;

        while 2*P < Q:
            t += 1
            Q /= 2

        print "Case #%d: %d" % (case+1, t)