#!/usr/bin/env python2.7

from collections import Counter
import random
import sys

def factorize(n):
  factors = []
  while n > 1:
    for i in [2, 3, 5, 7]:
      if n % i == 0:
        factors.append(i)
        n /= i
        break
  counter = Counter(factors)
  return [counter[2], counter[3], counter[5], counter[7]]

sys.stdin.readline()
R, N, M, K = map(int, sys.stdin.readline().strip().split())

vals = []
for i in range(R):
  vals.append([factorize(int(x)) for x in sys.stdin.readline().strip().split()])

known_results = []

# scan for 5s and 7s
max_5s = max([v[2] for x in vals for v in x])
max_7s = max([v[3] for x in vals for v in x])

known_results.extend([5] if max_5s > 0 else [])
known_results.extend([7] if max_7s > 0 else [])

# divide all numbers by 5 and 7
has_2 = False
has_3 = False
for v in vals:
  for i in range(K):
    if v[i] == [1, 0, 0, 0]: has_2 = True
    if v[i] == [0, 1, 0, 0]: has_3 = True

if has_2: known_results.append(2)
if has_3: known_results.append(3)

# randomly select 2 through 5
print("Case #1:")
for x in range(R):
  guess = list(known_results)
  while len(guess) != N:
    guess.append(random.choice(range(2, 6)))
  print("".join([str(i) for i in guess]))
