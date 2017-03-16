#!/usr/bin/env python
# vim: set fileencoding=utf-8 :
import sys
import fractions
def read_int(): return int(sys.stdin.readline())

def reduce_fraction(a, b):
  div = fractions.gcd(a, b)
  return (a//div, b//div)

def solve():
    p, q = [int(x) for x in sys.stdin.readline().strip().split('/')]
    p, q = reduce_fraction(p, q)
    if q & (q - 1) != 0:
        return 'impossible'

    count = 1
    while p * 2 < q:
        count += 1
        p *= 2

    return count

if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        print('Case #{}: {}'.format(i+1, solve()))
