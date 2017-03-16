primes = []
for n in range(2, 10 ** 6):
  is_prime = True
  for p in primes:
    if n % p == 0:
      is_prime = False
      break
    if p * p > n:
      break
  if is_prime:
    primes.append(n)


def decode_jamcoin(core_jamcoin):
  return 0b10000000000000000000000000000001 + 2 * core_jamcoin
  # return 0b1000000000000001 + 2 * core_jamcoin
  # return 0b100001 + 2 * core_jamcoin


def interpret(core_jamcoin, base):
  jamcoin = decode_jamcoin(core_jamcoin)
  value = 0
  for i in range(32):
  # for i in range(16):
  # for i in range(6):
    if (jamcoin >> i) & 1 == 1:
      value += base ** i;
  return value


def calculate_divisors(core_jamcoin):
  divisors = []
  for b in range(2, 11):
    value = interpret(core_jamcoin, b)
    has_divisor = False
    for p in primes:
      if value % p == 0:
        has_divisor = True
        divisors.append(p)
        break
      if p * p > value:
        break
    if not has_divisor:
      return None
  return divisors

print 'Case #1:'
count = 0
for cj in xrange(2 ** 30):
# for cj in range(2 ** 14):
# for cj in range(2 ** 4):
  ds = calculate_divisors(cj)
  assert ds == None or len(ds) == 9
  if ds != None:
    line = bin(decode_jamcoin(cj))[2:]
    for d in ds:
      line += ' ' + str(d)
    if count > 0:
      print line
    count += 1
    if count > 500:
      break

# print "HEY! DONE!"