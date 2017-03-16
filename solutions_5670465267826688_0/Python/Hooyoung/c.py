#!/usr/bin/env python

def times(a,b):
  if a == "1":
    return b
  if b == "1":
    return a
  if a == "-1":
    if b[0] == "-":
      return b[1:]
    return "-" + b[0]
  if a[0] == "-":
    return times("-1", times(a[1:], b))
  if b[0] == "-":
    return times("-1", times(a, b[1:]))
  return {
    "i": {"i": "-1", "j": "k", "k": "-j"},
    "j": {"i": "-k", "j": "-1", "k": "i"},
    "k": {"i": "j", "j": "-i", "k": "-1"}
  }[a][b]

def di(s, n):
  val = "1"
  for c in s:
    val = times(val, c)

  vval = "1"
  for i in xrange(n%4):
    vval = times(vval, val)
  if vval != "-1":
    return False

  madei = False
  val = "1"
  for c in s*min(n,16):
    val = times(val, c)
    if val == "i":
      madei = True
    elif val == "k" and madei:
      return True

  return False

T = int(raw_input())
for t in xrange(T):
  L,X = map(int,raw_input().split())
  s = raw_input().strip()
  print "Case #%d:" % (t+1), "YES" if di(s,X) else "NO"
