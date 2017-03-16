T = int(raw_input())
[N, J] = map(int, raw_input().split())

def toBase(num, base):
  res = 0
  m = 1
  while num:
    res += (num & 1) * m
    m *= base
    num >>= 1;
  return res  

MAX_PRIME = 1 << 17
is_prime = [True] * (MAX_PRIME+1)

p = 2
while p*p <= MAX_PRIME:
  k = 2 * p
  while k <= MAX_PRIME:
    is_prime[k] = False
    k += p
  if p == 2:
    p = 3
  else:
    p += 2
  while not is_prime[p] and p*p < MAX_PRIME: p += 2

primes = [p for p in xrange(2, MAX_PRIME) if is_prime[p]]

def getDivisor(n):
  for p in primes:
    if p*p > n:
      return 0
    if n % p == 0:
      return p
  return 0

def printBits(n):
  bits = []
  while n:
    bits.append(n&1)
    n >>= 1
  return "".join(map(str,reversed(bits)))

print("Case #1:");
for mid in xrange(1<<(N-2)):
  num = 1 | (mid << 1) | (1 << (N-1))
  is_ok = True
  divisors = []
  for base in xrange(2, 11): 
    divisor = getDivisor(toBase(num, base))
    if divisor == 0:
      is_ok = False
    divisors.append(divisor)

  if is_ok:
    print("%s %s" % (printBits(num), " ".join(map(str, divisors))))
    J -= 1

  if J == 0: break
