#!/usr/bin/python
import sys

def calc(his, others):
  counter = 0
  l = len(others)
  while counter < l:
    el = others[counter]
    if el < his:
      his += el
      counter+=1
      continue
    extra = 0
    if his == 1:
      return l
    while his <= el:
      his += his - 1
      extra += 1
    his += el
    return min(l-counter, extra+calc(his, others[counter+1:]))
      
  return 0

def main():
  h = file(sys.argv[1])
  n = int(h.readline())
  for j in xrange(1,n+1):
    A,N = [int(x) for x in h.readline().split(" ")]
    others = [int(x) for x in h.readline().split(" ")]
    others.sort()
    print "Case #%d: %s" % (j, calc(A, others))

main()
