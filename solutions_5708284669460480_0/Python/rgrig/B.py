#!/usr/bin/env python3

from collections import defaultdict

import math
import sys

def compute_failure(target):
  L = len(target)
  fail = [0] * L
  j = -1
  for i in range(L):
    fail[i] = j
    while j >= 0 and target[i] != target[j]:
      j = fail[j]
    j += 1
  #print(target, fail)
  return fail

def compute_transitions(keyboard, target):
  keyboard = sorted(set(keyboard))
  target = target + '#'
  L = len(target)
  result = {}
  fail = compute_failure(target)
  for i in range(L):
    for a in keyboard:
      j = i
      while j >= 0 and target[j] != a:
        j = fail[j]
      result[(i,a)] = j + 1
  #print('transition',sorted(result.items()))
  return result

def maximum(S, keyboard, target):
  K = len(keyboard)
  L = len(target)
  alphabet = sorted(set(keyboard))
  transitions = compute_transitions(keyboard, target)
  counts = [[0 for _ in range(L+1)] for _ in range(S+1)]
  for i in range(S):
    for j in range(L+1):
      if j > i:
        continue
      for a in alphabet:
        jj = transitions[(j, a)]
        new_count = counts[i][j] + (1 if jj == L else 0)
        counts[i+1][jj] = max(counts[i+1][jj], new_count)
  #print ('COUNTS',counts)
  result = max(counts[S][j] for j in range(L+1))
  #print('maximum', result)
  return result

def expected(S, keyboard, target):
  K = len(keyboard)
  L = len(target)
  counts = defaultdict(int)
  for a in keyboard:
    counts[a] += 1
  probability = 0
  for t in target:
    probability += math.log(counts[t]) - math.log(K)
  probability = math.exp(probability)
  #print('probability', probability)
  return (S-L+1) * probability

def solve(S, keyboard, target):
  #print (S, keyboard, target)
  if not (set(keyboard) >= set(target)):
    return 0
  return maximum(S, keyboard, target) - expected(S, keyboard, target)

if __name__ == '__main__':
  xs = [x.strip() for x in sys.stdin.readlines()]
  for t in range(1,len(xs),3):
    ys, keyboard, target = xs[t:t+3]
    [K, L, S] = [int(x) for x in ys.split()]
    assert (K == len(keyboard))
    assert (L == len(target))
    result = solve(S, keyboard, target)
    sys.stdout.write('Case #{}: {}\n'.format((t-1)//3+1, result))
    sys.stdout.flush()
