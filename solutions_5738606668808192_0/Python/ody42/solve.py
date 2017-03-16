import sys

def to_base(binary, base):
    ret = 0
    mult = 1
    while binary:
        ret += mult * (binary & 1)
        mult *= base
        binary >>= 1

    return ret

# This looks to suffice.
# We may fail to find many coins this way, but we will probably find enough.
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
def get_divisor(x):
    for p in primes:
        if x % p == 0:
            return p
    return None
    

def slow(N, J):
    # All numbers, that in binary, have N digits, with the first and
    # the last being both 1.
    binary_candidates_begin = 2**(N-1)+1
    binary_candidates_end = 2**N
    binary_candidates_step = 2
    
    # Their count should be 2**(N-2).

    # We will probably not exhaust that range to find J jamcoins though.

    bases = range(3,10+1)
    coins = []
    binary = binary_candidates_begin
    while binary < binary_candidates_end:
        divisors = []

        # Try to find a divisor for base 2:
        divisor = get_divisor(binary)
        if divisor is None:
            binary += binary_candidates_step
            continue
        divisors.append(divisor)

        # Try to find a divisor for bases 3 to 10:
        for base in bases:
            x = to_base(binary, base)
            divisor = get_divisor(x)
            if divisor is None:
                break
            divisors.append(divisor)
        else:
            coins.append((bin(binary).partition('b')[2], divisors))
            if len(coins) == J:
                break

        binary += binary_candidates_step
            
    assert len(coins) == J
    return coins

def solve(N, J):
    return slow(N, J)

def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        N, J = map(int, sys.stdin.readline().strip().split())
        JAMCOINS = solve(N, J)
        print 'Case #%s:' % (i+1)
        for (coin, divisors) in JAMCOINS:
            assert all(c == '1' or c == '0' for c in coin)
            assert len(divisors) == 9
            print coin, ' '.join(map(str,divisors))

if __name__ == '__main__':
    main()
