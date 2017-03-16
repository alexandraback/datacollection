#!/usr/bin/python

from sys import stdin as I

matrix = {
  'ee': 'e', 'ei': 'i', 'ej': 'j', 'ek': 'k',
  'ie': 'i', 'ii': 'E', 'ij': 'k', 'ik': 'J',
  'je': 'j', 'ji': 'K', 'jj': 'E', 'jk': 'i',
  'ke': 'k', 'ki': 'j', 'kj': 'I', 'kk': 'E'
}

def eval(s):
  l = s.lower()
  r = matrix[l]
  return (r == r.lower()) == ((s[0] == l[0]) != (s[1] == l[1])) and r.upper() or r.lower()

def solve():
  L, X = map(int, I.readline().split())
  Li = I.readline()

  def getChar(pos):
    if pos < X * L:
      return Li[pos % L]
    else:
      return 'e'

  def waitForChar(offset, c):
    pos = offset
    thresh = pos + 4 * L
    current = 'e'
    while pos < thresh and current != c:
      current = eval(current + getChar(pos))
      pos += 1
    return (current == c, pos)

  (succ, pos) = waitForChar(0, 'i')
  if not succ: return False
  (succ, pos) = waitForChar(pos, 'j')
  if not succ: return False
  (succ, pos) = waitForChar(pos, 'k')
  if not succ: return False

  current = 'e'
  thresh = pos + (X * L - pos) % (4 * L)
  while pos < thresh:
    current = eval(current + getChar(pos))
    pos += 1

  return current == 'e'

T = int(I.readline())
for i in range(T):
    print("Case #%i: %s" % (i+1, solve() and "YES" or "NO"))
