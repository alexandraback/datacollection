#!/usr/bin/python
import sys

def calc(name, n):
  vowels = ['a', 'e', 'i', 'o', 'u']
  vcount = 0
  s = 0
  last = -1
  for i, l in enumerate(name):
    if l not in vowels:
      vcount += 1
    else:
      vcount = 0
    if vcount >= n:
      curr = i - n + 1
      s += (curr-last)*(len(name)-i)
      last = curr
  return s

def main():
  h = file(sys.argv[1])
  n = int(h.readline())
  for j in xrange(1,n+1):
    name, n = h.readline().split(" ")
    print "Case #%d: %s" % (j, calc(name, int(n)))

main()
