from fractions import Fraction
import math

f = open('a_small.txt')
T = int(f.readline())
for turn in range(1, T+1):
  P,Q = [int(x) for x in f.readline().split("/")]
  fraction = Fraction(P,Q)
  P = fraction.numerator
  Q = fraction.denominator
  if Q > 2**40 or 2**round(math.log(Q, 2)) != Q :
    print "Case #" + str(turn) + ":", "impossible"
  else:
    count = 1
    while Q > 2*P:
      P*=2
      count += 1
    print "Case #" + str(turn) + ":", count