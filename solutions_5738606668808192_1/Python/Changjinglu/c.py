num_bits = 32
coins_needed = 500

limit = 2 ** 16
primes = []
not_prime = (limit + 1) * [ False ]
pos = 2
while pos <= limit:
  while pos <= limit and not_prime[pos]:
    pos += 1
  primes.append(pos)
  for i in range(pos * pos, limit + 1, pos):
    not_prime[i] = True
  pos += 1

def find_divisor(x):
  for a in primes:
    if a * a > x:
      return None
    if x % a == 0:
      return a

print('Case #1:')
chars = num_bits * [ '0' ]
chars[0] = chars[-1] = '1'
coins = 0
while coins < coins_needed:
  s = ''.join(chars)
  pos = num_bits - 2
  while chars[pos] == '1':
    chars[pos] = '0'
    pos -= 1
  chars[pos] = '1'
  divisors = []
  for base in range(2, 11):
    x = int(s, base)
    d = find_divisor(x)
    if d == None:
      break
    divisors.append(d)
  if len(divisors) < 9:
    continue
  print(s + ' ' + ' '.join(map(str, divisors)))
  if False:
    for base in range(2, 11):
      x = int(s, base)
      d = find_divisor(x)
      c = x // d
      print('%d: %d = %d * %d' % (x, d * c, d, c))
  coins += 1
