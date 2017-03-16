#!/usr/bin/python
import sys
t = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', ' ': ' '}

def calc(s):
  ret = []
  for c in s:
    ret.append( str(t[c]))
  return "".join(ret)

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  for j in xrange(1, n+1):
    print "Case #%d: %s" % (j, calc(d[j][:-1]))

main()
