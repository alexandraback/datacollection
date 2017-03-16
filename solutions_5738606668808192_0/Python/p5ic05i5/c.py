

def onediv(k):
    for i in xrange(2, int(k ** 0.5)+1):
        if k % i == 0:
            return i
    return 1

def inbase(k, b):
    m = 1
    r = 0
    for i in xrange(N):
        if k & (m << i):
            r += b ** i
    #print "{} ({:b}) in base {} -> {}".format(k, k, b, r)
    return r;

T = int(raw_input())
for x in xrange(1, T+1):
    N, J = map(int, raw_input().split())
    print "Case #{}:".format(x)
    start = (1 << (N-1)) + 1
    end = (1 << N) - 1
    for k in xrange(start, end+1, 2):
        D = {}
        prime = False
        for b in xrange(2, 11):
            K = inbase(k, b)
            D[b] = onediv(K)
            prime = D[b] == 1
            if prime:
                break

        if not prime:
            print "{:b}".format(k),
            for b in xrange(2, 11):
                print " {}".format(D[b]),
            print ""
            J -= 1

        if J == 0:
            break
