import sys
import random

random.seed(12345) # deterministic randomness?
def gen_number(N):
    '''Return a binary number of length N with the first and last bit set'''
    assert(N > 2)
    while True:
        yield (1<<(N-1)) + 2*random.getrandbits(N-2) + 1


_prime_sieve = [True,True,False] + [False,True]*int(1e6)
_primes = []
def prime_sieve():
    _primes.append(2)
    for i in range(3,len(_prime_sieve),2):
        if not _prime_sieve[i]:
            _primes.append(i)
            for j in range(i+i, len(_prime_sieve), i):
                _prime_sieve[j] = True

def get_divisor(n):
    '''Try to find and return a non-trivial divisor for n'''
    if n < len(_prime_sieve) and not _prime_sieve[n]:
        return None # n is prime
    for p in _primes:
        if (n%p) == 0:
            return p
    return None

_seen = set()
def solve(n):
    if n in _seen:
        return None
    _seen.add(n)
    ns = format(n, 'b')
    divs = [ns]
    for base in range(2,11):
        nb = int(ns, base=base)
        d = get_divisor(nb)
        if d:
            divs.append(str(d))
        else:
            return None
    return ' '.join(divs)

if __name__ == '__main__':
    prime_sieve()
    sys.stdin.readline()
    N,j = (int(x) for x in sys.stdin.readline().split())
    print('Case #1:')
    for n in gen_number(N):
        ans = solve(n)
        if ans:
            print(ans)
            j -= 1
            if j == 0:
                break
