import sys

def isprime(n):
    j = 3
    while j * j <= n:
        if n % j == 0:
            return j
        j += 2
    return None

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, J = map(int, f.readline().split())

        print "Case #%d:" % (_T + 1,)

        t = (2**(N-1)) - 1
        while J:
            t += 2
            s = bin(t)[2:]
            assert len(s) == N
            # print s

            divisors = map(isprime, [int(s, b) for b in xrange(2, 11)])
            # print divisors
            if all(divisors):
                J -= 1
                print s, " ".join(map(str, divisors))
