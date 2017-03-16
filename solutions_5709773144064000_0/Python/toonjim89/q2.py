import sys
f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    ttotal = 0.0
    rate = 2.0
    A = []
    A += [map(float,f.readline().split())]
    C = A[0][0]
    F = A[0][1]
    X = A[0][2]
    if X < C:
        ttotal = X/rate
    else:
        while (X-C)/rate > X/(rate+F):
            ttotal = ttotal + (C/rate)
            rate = rate + F
        ttotal = ttotal + X/rate
    ttotal = round(ttotal,7)
    print "Case #%d: %0.7f" % (t+1,ttotal)
