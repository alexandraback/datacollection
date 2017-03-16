#!/usr/bin/python

import sys

def toInt(a):
  return int(a)

intext = "ejp mysljylc kd kxveddknmc re jsicpdrysi"+ "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+ "de kr kd eoya kw aej tysr re ujdr lkgc jv"
outtext = "our language is impossible to understand"+ "there are twenty six factorial possibilities"+ "so it is okay if you want to just give up"

maptext = {}
for i in range(0, len(intext)):
  c = intext[i]
  maptext[ c ] = outtext[i]
maptext[ "z" ] = "q"
maptext[ "q" ] = "z"
#print maptext

import sys

N = int(sys.stdin.readline())
for test in range(0, N):
  text = sys.stdin.readline().rstrip('\n')
  result = ""
  for c in text:
    result += maptext[ c ]

  print "Case #%d: %s" % (test+1, result)
