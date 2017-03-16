from operator import mul    # or mul=lambda x,y:x*y

def nCk(n, k):
    if n == 0:
        return 0
    return reduce(mul, (1.0*(n-i)/(i+1) for i in xrange(k)), 1)

def solve(N, X, Y):

    # find k
    k = 0
    while True:
        if (k+1)*(2*k+1) > N:
            break
        k += 1
    k -= 1
    S = (k+1)*(2*k+1)
    r = N - S

    posIdx = abs(X) + abs(Y)
    if posIdx <= 2*k:

        return 1
    elif posIdx >= 2*(k+2):
        return 0
    else:

        h = r - 2*(k+1)

        if h > 0:
            if abs(Y) < h:
                return 1
            rr = 4*(k+1) - r
            return 1.0*nCk(rr, abs(Y) - h)/pow(2, rr)
        else:
            return 1.0*nCk(r, abs(Y)+1)/pow(2, r)
    
def main():
    import sys
    readline = sys.stdin.readline
    T = int(readline())

    for i in range(T):
        N, X, Y = map(int, readline().split())
        print "Case #%d: %f" % (i+1, solve(N, X, Y))
main()
