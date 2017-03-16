# Google's code jam - Round 1C

import sys
import collections
import itertools
from fractions import gcd
from math import sqrt

inp = sys.stdin
outp = sys.stdout

def factor2(n):
  e = 0

  while n >= 2:
    n /= 2
    e += 1

  return e

# Solution function
def solve():
  input_line = raw_input()
  numerador = int(input_line.split("/")[0])
  denominador = int(input_line.split("/")[1])

  MCD = gcd(numerador,denominador)
  numerador /= MCD
  denominador /= MCD

  UBofG = factor2(denominador)

  #print (MCD, numerador, denominador, UBofG)

  # Pure human
  if numerador == 0:
    print "impossible"
    return

  # Pure elf
  if numerador == denominador:
    print 0
    return

  # Degenerated case
  if numerador > denominador:
    print "impossible"
    return

  # Out of the 2**40 limit
  if UBofG > 40:
     print "impossible"
     return

  # No possible combination
  if denominador != 2**UBofG:
    print "impossible"
    return

  while numerador > 1:
    numerador /= 2
    UBofG -= 1

  if UBofG < 1:
    print "impossible"
    return

  print UBofG


# Main
T = int(inp.readline())
for i in range(T):
    outp.write('Case #%d: ' % (i+1))
    solve()
