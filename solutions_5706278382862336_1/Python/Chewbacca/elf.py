#! /usr/bin/env python3
import sys
# (c) Krzysztof 'Chris' Leszczynski
# Please don't think I write programs in this way.
# I am in hurry, this is code jam, you know.
# Anyway, if you think you spotted a bug, send me a line
# to chris@camk.edu.pl

twos = [ (1<<_) for _ in range(50) ]

def GCD(a,b):
    a, b = abs(a), abs(b)
    a, b = max(a,b), min(a,b)
    while True:
        if b==0:
            return a
        a, b = b, a%b

def solve(a,b):
    gcd = GCD(a,b)
    a /= gcd
    b /= gcd
    if a>b or b not in twos: return "impossible"
    generation = 0
    while a<b:
        a += a
        generation += 1
    return generation

def run_tests(input):
    test_cases = int(input.readline())
    for test_no in range(1,test_cases+1):
        A = list(map(int, input.readline().split("/") + [1]))
        print("Case #{}: {}".format(test_no, solve(A[0],A[1])))


if __name__ == "__main__":
  if len(sys.argv) > 1:
    if sys.argv[1] == 'test':
        assert(GCD3(5555550,2222220)==2222220/2)
        assert(GCD((5555550,4444440,2222220))==2222220/2)
        sys.exit(0)
  try:
      input = open(sys.argv[1],"r")
  except (IOError, IndexError):
      input = sys.stdin
  run_tests(input)
