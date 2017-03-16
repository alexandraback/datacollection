import sys

def solve(N):
    if N == 0:
        return None
    k = 1
    S = N
    digits = set()
    while True:
        digits = digits.union( str(S) )
        #print S, digits
        if len(digits) == 10:
            break
        k += 1
        S += N
    return S


if __name__ == "__main__":
    fd = open( sys.argv[1] )
    T = int( fd.readline() )
    for t in xrange(T):
        n = int(fd.readline())
        s = solve(n)
        if s is None:
            print "Case #%d: INSOMNIA" % (t+1)
        else:
            print "Case #%d: %d" % (t+1, s)
    fd.close()
