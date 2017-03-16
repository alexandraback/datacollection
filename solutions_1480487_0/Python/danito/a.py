#!/usr/bin/python -tt

import decimal

var1 = []
var2 = 0
def main(lst):
  S = map(int, lst.split(" "))
  N = S.pop(0)

  total = 0
  for i in S:
    total = total + i

  res = ""
  N2 = N
  total2 = 2*total
  for i in S:
    if (2*total-i*N)<0:
      N2 = N2-1
      total2 = total2 - i

  for i in S:
    if (2*total-i*N)<0: res = res + " " + "%0.6f" % 0
    else: res = res + " " + "%0.6f" % (decimal.Decimal(total2-i*N2)*100/(N2*total))
  return res.strip()



if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    res = main(sys.stdin.readline().strip())
    print "Case #%d: %s" % (i + 1, res)



