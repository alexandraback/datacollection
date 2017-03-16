def build_primes(n):
  is_prime = [1] * (n + 1)
  primes = [2, 3]
  p = 5
  while p <= n:
    if is_prime[p]:
      primes.append(p)
      for q in range(p*p, n + 1, 2*p):
        is_prime[q] = 0
    p += 2
    if p > n: break
    if is_prime[p]:
      primes.append(p)
      for q in range(p*p, n + 1, 2*p):
        is_prime[q] = 0
    p += 4
  return primes

def is_prime(n):
  d = 2
  while d*d <= n:
    if n % d == 0:
      return d
    d += 1
  return 0

length = 16
size = 50

answer = []
for i in range(1 << (length-2)):
  x = '1' + bin(i)[2:].rjust(length-2, '0') + '1'
  partial = []
  for b in range(2, 11):
    d = is_prime(int(x, b))
    if not d:
      break
    partial.append(d)
  if len(partial) == 9:
    answer.append((x, partial))
  if len(answer) == size:
    break

print 'Case #1: \n' + '\n'.join(map(lambda (x, partial): 
      '{} {}'.format(x, ' '.join(map(str, partial))),
      answer))
