#!/usr/bin/python
import json, sys

file = open('primes.json', 'r')
sorted_primes = json.loads(file.read())

T = int(sys.stdin.readline().strip())

def divisible_by(x):
  # find primes and iterate through instead
  for i in sorted_primes:
    if i >= x:
      raise RuntimeError('well really fuck')
    if x % i == 0:
      return i 
  raise RuntimeError('well, fuck %d' % x)

def switch_base(x, b):
  return int(x, b)

def gen_binaries(N, fake=True):
  if N == 1:
    yield '1'
  else:
    for c in gen_binaries(N - 1):
      if fake:
        yield '0' + c
      yield '1' + c

for t in xrange(T):
  N, J = [int(x) for x in sys.stdin.readline().split()]
  print 'Case #%d:' % (t + 1)

  for x in gen_binaries(N, False):
    nums = [-1] * 9
    works = True
    for i in range(10, 1, -1):
      for d in sorted_primes:
        s = switch_base(x, i)
        if d >= s:
          break
        if s % d == 0:
          nums[i - 2] = d
          break
      if nums[i - 2] == -1:
        works = False
        break
    if not works:
      continue

    print '%s %s' % (x, ' '.join([str(x) for x in nums]))
    
    # only print up to J amount
    J -= 1
    if J == 0:
      break
