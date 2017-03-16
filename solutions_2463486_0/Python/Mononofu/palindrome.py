import time
import cProfile
import operator
import sys


def is_palindrome(n):
  return n == n[::-1]


def palindromes_raw():
  for n in range(0, 10):
    yield str(n)

  for n in range(0, 10):
    yield "%d%d" % (n, n)

  for p in palindromes_raw():
    for n in range(0, 10):
      yield "%s%s%s" % (n, p, n)


def palindromes():
  for p in palindromes_raw():
    if p[0] == '0':
      continue
    yield p


"""
start = time.time()
pals = [n for n in range(1, 10000000) if is_palindrome(str(n))]
#print pals
print len(pals)
print time.time() - start"""


def find_fair_square():
  start = time.time()
  gen_pals = []
  mapping = {}
  gen = palindromes()
  while True:
    p = int(gen.next())
    if p > 10**8:
      break
    sqr = p*p
    if is_palindrome(str(sqr)):
      gen_pals.append(sqr)
      mapping[p] = sqr

  #print gen_pals
  #print len(gen_pals)
  #print time.time() - start
  mapping = sorted(mapping.iteritems(), key=operator.itemgetter(1))
  for a, b in mapping:
    #print "%d: %d" % (a, b)
    pass
  return gen_pals


def binary_search(x, xs, low, high):
  if low >= high:
    return high

  median = (low + high) / 2
  if x > xs[median]:
    return binary_search(x, xs, median+1, high)
  if x < xs[median]:
    return binary_search(x, xs, low, median-1)
  else:
    return median

pals = sorted(find_fair_square())
num_cases = int(sys.stdin.readline())
#print pals[:10]
for i in range(num_cases):
  print "Case #%d:" % (i + 1),

  a, b = sys.stdin.readline().strip().split(" ")
  a, b = int(a), int(b)

  a_i = binary_search(a, pals, 0, len(pals))
  b_i = binary_search(b, pals, 0, len(pals))

  count = b_i - a_i
  if(pals[a_i] > a and pals[a_i] <= b):
    count += 1

  pal_interval = [p for p in pals if p >= a and p <= b]
  #print "%d <= x <= %d -- %d:%d -- %d - %d" % (a, b, a_i, b_i, count, len(pal_interval))
  print "%d" % len(pal_interval)




#cProfile.run('find_fair_square()')
