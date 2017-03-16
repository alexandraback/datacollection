import itertools

LEN = 16
SIZE = 500

def merge(n1, n2):
  n = ''
  for i in range(LEN/2):
    n += n1[i] + n2[i]
  return n

def is_jamcoin(n, divs):
  for i, b in enumerate(range(2, 11)):
    x = int(n, b)
    if x % divs[i]:
      print x, 'base', b, 'mod', divs[i], '!= 0' 
      return False
  return True


divs = range(3, 12)
str_divs = ' '.join(map(str, divs))

ns = [[] for _ in range(LEN/2)]
for n in range(1 << (LEN/2 - 1)):
  x = bin(n)[2:].rjust(LEN/2, '0')
  ns[x.count('1')].append(x)


print 'Case #1: '

count = 0
for i in range(LEN/2):
  for n1, n2 in itertools.product(ns[i], ns[i]):
    n = '1' + merge(n1, n2) + '1'
    # assert is_jamcoin(n, divs)
    print n, str_divs
    count += 1
    if count == SIZE:
      break
  if count == SIZE:
    break
