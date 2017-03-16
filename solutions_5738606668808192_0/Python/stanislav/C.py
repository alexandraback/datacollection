import sys
import math


def divisor(n):
  for i in range(2, min(10, int(math.ceil(math.sqrt(n))))):
    if n % i == 0: return i
  return None

def valid(s):
  result = []
  for base in range(2, 11):
    n = int(s, base)
    d = divisor(n)
    if d is None: return None
    else: result.append(d)
  return result

def gen(N):
  for i in range(0, 10000000):
    yield "1" + ("{0:0" + str(N-2) + "b}").format(i) + "1"

def run(t):
  N, J = map(int, raw_input().split())
  print('Case #{}:'.format(t))
  cnt = 0
  for s in gen(N):
    ds = valid(s)
    if ds is not None:
      print(s + " " + " ".join([str(d) for d in ds]))
      cnt += 1
      if cnt == J: return

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
