from sys import stdin
from decimal import *

getcontext().prec = 5000

def read_ints(): return map(int, stdin.readline().split())

def main():
    cases = int(stdin.readline())
    for case in xrange(1, cases + 1):
        r, t = read_ints()
        
        a1 = r * 2 + 1
        b = a1 - 2
        d = Decimal(b * b + 8 * t)
        rings = (-b + d.sqrt()) / 4
        
        ans = int(rings)
        print('Case #{}: {}'.format(case, ans))
        
main()