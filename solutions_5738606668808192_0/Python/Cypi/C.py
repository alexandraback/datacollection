MAX_PRIME=100

numbers = range(2, MAX_PRIME+1)
is_prime = [True]*len(numbers)
primes = []

for i in range(len(numbers)):
  if is_prime[i]:
    primes.append(numbers[i])
    for j in range(i+numbers[i], len(numbers), numbers[i]):
      is_prime[j] = False

def find_divisor(s, b):
  m = int(s, b)
  for p in primes:
    if p >= m: return -1
    if m%p == 0:
      return p
  return -1

_T = int(raw_input())
for _t in range(1, _T+1):
  print 'Case #{}:'.format(_t)

  N, J = map(int, raw_input().split())

  found = 0

  for n in range(1<<(N-2), 1<<(N-1)):
    s = bin(n)[2:] + '1'
    D = []
    for b in range(2, 11):
      d = find_divisor(s, b)
      if d == -1: break
      D.append(d)
    if len(D) < 9: continue
    print '{} {}'.format(s, ' '.join(map(str, D)))
    found += 1
    if found >= J: break
