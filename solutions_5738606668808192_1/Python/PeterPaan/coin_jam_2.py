#!/usr/bin/python3
import sys
N = 32
J = 500
MAX_N = 1 << (N-2)
LEFT_1 = 1 << (N-1)

def bin_to_base(candidate, base):
  return int("{:b}".format(candidate), base)

def find_divisor(n):
  if n % 2 == 0:
    return 2, True
  else:
    divisor = 3
    while divisor * divisor <= n and divisor <= 1000000:
      if n % divisor == 0:
        return divisor, True
      divisor += 2
    return 0, False

def main():
  print("Case #1:")
  found = 0
  n = 0
  while found < J and n < MAX_N:
    candidate = LEFT_1 + (n << 1) + 1
    divisors_for_base = [0 for _ in range(2, 11)]
    ok = True
    base = 2
    while ok and base <= 10:
      candidate_in_base = bin_to_base(candidate, base)
      div, found_div = find_divisor(candidate_in_base)
      if found_div:
        divisors_for_base[base-2] = div
      else:
        ok = False
        break
      base += 1
    if ok:
      found += 1
      print("{:b} {} {} {} {} {} {} {} {} {}".format(candidate, *divisors_for_base))
    n += 1


main()
