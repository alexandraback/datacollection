#! /usr/vin/env python

import sys



def main():
  T = input()
  for n in range(T):
    a, b = map(int, raw_input().split())
    p = map(float, raw_input().split())

    t = []
    for i in range(a + 1):
        t.append(backe(p, i, a, b))

    t.append(b + 2)
    print 'Case #%s: %.6f' % (n + 1, min(t))

def backe(p, i, a, b):
  q = list(p[:a - i])
  x = reduce(float.__mul__, q, 1.0)
  short = (i * 2 + b - a + 1)
  long = short + b + 1
  return x * short + (1 - x) * long


main()
