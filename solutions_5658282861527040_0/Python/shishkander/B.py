def FF(f):
    def w(*args):
        ags = list(A[1:] for A in args)
        r = f(*ags)
        #print "\t", r, " <=", f.__name__, ' '.join(map(repr, ags))
        return r
    return w


@FF
def psolve_(A, B, K):
    return solve(A, B, K)


def psolve_a(B, K):
    return psolve_b(B, K)


@FF
def psolve_b(A, K):
    B = '1' * len(A)
    return solve(A, B, K)


@FF
def psolve_k(A, B):
    if not A:
        return 1
    return TwoInt(A) * TwoInt(B)


@FF
def psolve_ab(K):
    B = A = '1' * len(K)
    return solve(A, B, K)


def psolve_ak(B):
    return psolve_bk(B)


@FF
def psolve_bk(A):
    return TwoInt(A) * (2 ** len(A))


def psolve_abk(N):
    return (2 ** N) ** 2


def TwoInt(A):
    # print "TwoInt ", repr(A)
    if not A:
        return 1
    return int(A, 2) + 1


def REM(f):
    R = {}

    def w(A, B, K):
        try:
            # print "call ", ' '.join(map(repr, [A, B, K]))
            return R[(A, B, K)]
        except:
            r = f(A, B, K)
            # print r, "<=", ' '.join(map(repr, [A, B, K]))
            R[(A, B, K)] = r
            return r
    return w


@REM
def solve(A, B, K):
    if not A:
        return 1
    a, b, k = A[0], B[0], K[0]
    if a > b:
        return solve(B, A, K)
    c = a + b + k
    if c == '000':
        return psolve_(A, B, K)
    if c == '110':
        # a0,b1   a1,b0    a0,b0
        return psolve_a(B, K) + psolve_b(A, K) + psolve_ab(K)
    if c == '010':
        # a0,b1   a0,b0
        return psolve_(A, B, K) + psolve_b(A, K)
    if c == '001':
        # a0,b0
        return psolve_k(A, B)
    if c == '111':
        # a0,b0  a1,b0  a0,b1  a1,b1
        return psolve_abk(len(K) - 1) + psolve_bk(A) + psolve_ak(B) + psolve_(A, B, K)
    if c == '011':
        # a0,b0  a0,b1
        return psolve_bk(A) + psolve_k(A, B)
    assert False
    print "weird"


def inta(s):
    B = 40
    if len(s) < B:
        s = '0' * (B - len(s)) + s
    return s


def CASE(IN):
    def rstr():
        return IN.readline().strip()

    def rint():
        return int(rstr())

    def rints():
        return map(int, rstr().split())
    a, b, k = rints()
    A, B, K = map(lambda x: inta(bin(x - 1)[2:],), [a, b, k])
    #print a, b, k
    #print A, B, K
    return solve(A, B, K)


def RUN(IN, OUT):
    t = int(IN.readline().strip())
    for i in xrange(1, t + 1):
        OUT.write("Case #%i: %i\n" % (i, CASE(IN)))

if __name__ == "__main__":
    import sys
    RUN(sys.stdin, sys.stdout)
