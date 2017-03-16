import random
 
TRIALS = 5 
 
def is_probable_prime(n):
  assert n >= 2    
  if n == 2: return True
  if n % 2 == 0: return False
  s, d = 0, n-1
  while True:
    quotient, remainder = divmod(d, 2)
    if remainder == 1: break
    s += 1
    d = quotient
  assert(2**s * d == n-1)

  def try_composite(a):
    if pow(a, d, n) == 1: return False
    for i in range(s):
      if pow(a, 2**i * d, n) == n-1: return False
    return True

  for i in range(TRIALS):
    a = random.randrange(2, n)
    if try_composite(a): return False
  return True 


primes = [p for p in range(2, 1000) if is_probable_prime(p)]

def is_prime(n):
  for p in primes:
    if n % p == 0: return False
  return True

def get_divisor(n):
  for p in primes:
    if n % p == 0: return p
  return None

t = int(input())
[n, j] = list(map(int, input().split()))

s = ['1'] + (n-2) * ['0'] + ['1']
string = ''.join(s)
x = [int(string, base) for base in range(2, 11)]

ans = []
while len(ans) < j:
  for i in range(n-2, 0, -1):
    if s[i] == '0':
      s[i] = '1'
      break
    else:
      s[i] = '0'
  string = ''.join(s)
  x = [int(string, base) for base in range(2, 11)]
  if any(map(is_prime, x)): continue
  ans.append(x)

print('Case #1:')
for x in ans: 
  print(' '.join(list(map(str, x[-1:] + list(map(get_divisor, x))))))