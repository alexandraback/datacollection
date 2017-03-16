#!/usr/bin/python -tt

def main(X,Y):
  trip = ""
  #small case: 0 <= |X|, |Y| <= 100. => abs(X) + abs(Y) <= 250
  if abs(X) + abs(Y) <= 250:
    if X >=0: trip = trip + "WE"*abs(X)
    else: trip = trip + "EW"*abs(X)
    if Y >=0: trip = trip + "SN"*abs(Y)
    else: trip = trip + "NS"*abs(Y)
  return trip


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    X,Y = map(int,sys.stdin.readline().strip().split(" "))
    res = main(X,Y)
    print "Case #%d: %s" % (i + 1, res)



