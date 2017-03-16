# -*- coding: utf-8 -*-

# Qualification Round 2016
# Problem C. Coin Jam

primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257]

def find_a_divisor(num):
  for p in primes:
    if p ** 2 > num:
      return 1
    if num % p == 0:
      return p
  return 1

def base10from(num, b):
  x = 0
  numlist = list(num)
  while (numlist):
    x *= b
    x += int(numlist.pop(0))
  return x


T = int(input())
N, J = [int(s) for s in input().split(" ")]

s = 0
jamcoins = []
format_type = "".join(["0", str(N - 2), "b"])

while len(jamcoins) < J:
  middle_digits = str(format(s, format_type))
  n = "".join(["1", middle_digits, "1"])
  divisors = [1, 1, 1, 1, 1, 1, 1, 1, 1]

  for k in range(2, 11):
    d = find_a_divisor(base10from(n, k))
    if d == 1:
      break
    divisors[k - 2] = d

  if 1 in divisors:
    pass
  else:
    jamcoins.append({"n" : n, "divisors" : divisors})

  s += 1
  if s >= 2 ** (N - 2):
    break


print("Case #1:")
for i in jamcoins:
  ans = str(i["n"]) + " " + " ".join(map(lambda x: str(x), i["divisors"]))
  print (ans)


