from itertools import product
from math import sqrt

def smallest_divisor(n):
  for i in range(2, int(sqrt(n))+1):
    if n%i == 0:
      return i
  return -1


N = 16
J = 50

inner_len = N-2
results = {}
for inside in product("01", repeat=inner_len):
  n = '1'+''.join(inside)+'1'
  divisors = []
  match = True
  for base in range(2, 11):
    k = int(n, base)
    d = smallest_divisor(k)
    print(k, d)
    if d > 0:
      divisors.append(str(d))
    else:
      match = False
      break
  if match:
    results[n] = divisors
    print(n, divisors)
  if len(results) > J-1:
    break



f = open("small.out", 'w')
f.write("Case #1:\n")
for n, d in results.items():
  f.write("{} {}\n".format(n, " ".join(d)))