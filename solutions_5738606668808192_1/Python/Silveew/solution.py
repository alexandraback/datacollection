import itertools
import time

def read_int(): return int(raw_input())
def read_pair(): return [int(x) for x in raw_input().strip().split(' ')]

T = read_int()
N, J = read_pair()

def combine(digits, base):
    number = 0
    for digit in digits:
        number *= base
        number += digit
    return number

def getPrimesUpTo(upper_bound):
  primes = []
  sieve = [True for _ in range(upper_bound)]
  sieve[0] = False
  sieve[1] = False
  for p in range(2,upper_bound):
    if sieve[p]==True:
      primes.append(p)
      m = 2*p
      while m < upper_bound:
        assert p > 1
        sieve[m] = p
        m += p
  return primes, sieve

PRIMES_BOUND = int(10**(N/2.))
PRIMES_BOUND = 10**8  # just generate a lot of primes

# Generating primes takes up to a minute
primes, sieve = getPrimesUpTo(PRIMES_BOUND)
#is_prime_dict = {p:True for p in primes}

def find_divisor(x):
  if x <= PRIMES_BOUND:
    div = sieve[x]
    # div == 1 iff x is prime
    return div if div > 1 else False
  else:
    for p in primes:
      if x % p == 0:
        return p
    # If we didn't generate enough primes, it could be we can't find a divisor
    # but this is unlikely
    return False


def iter_jamcoins_strings(N):
  assert N >= 2
  for digits in itertools.product(range(2), repeat=N-2):
    yield [1] + list(digits) + [1]

# Iterate over all possible jamcoins
print 'Case #1:'
for d in iter_jamcoins_strings(N):
  divs = []
  for base in range(2, 11):
    d_base = combine(d, base)
    div = find_divisor(d_base)
    if div:
      divs.append(div)
    else:
      break
  else:
    # If we didn't break, we found a solution
    d_string = ''.join(map(str, d))
    print "%s %d %d %d %d %d %d %d %d %d" % tuple([d_string] + divs)
    J-=1
    if J == 0:
      break
    #print d_base
