import sys

_filename = sys.argv[1]
_in = open(_filename)
def ints():
    return map(int, _in.readline().split())
def raw():
    return _in.readline().rstrip('\n')
raw_input = raw # we all forget sometimes

def primes(n):
    if n < 2:
        return []
    primes = [2]
    p = 3
    while p < n:
        prime = True
        for q in primes:
            if q * q > p:
                break
            if p % q == 0:
                prime = False
                break
        if prime:
            primes.append(p)
        p += 2
    return primes

def get_prime(n, P):
    for p in P:
        if n % p == 0:
            return p

def jammy_cert(s, P):
    ret = []
    for b in range(2,11):
        n = int(s, b)
        p = get_prime(n, P)
        if not p:
            return
        ret.append(p)
    return ret

def bf(N, J):
    # try with small number of primes
    P = primes(100)
    found = dict()
    for bits in range(2**(N-2)):
        if len(found) == J:
            return found
        fmtstr = "1{:0>" + str(N-2) + "b}1"
        s = fmtstr.format(bits)
        cert = jammy_cert(s, P)
        if cert:
            found[s] = cert
    raise ValueError('not enough primes')

def solve(N, J):
    found = bf(N, J)
    assert len(found) == J
    lines = ["{} {}".format(s, ' '.join(map(str, found[s]))) for s in found] 
    return "\n" + "\n".join(lines)

if __name__ == '__main__':
    num_cases, = ints()
    for case_num in xrange(1, num_cases + 1):
        N, J = ints()
        print "Case #{}: {}".format(case_num, solve(N, J))
