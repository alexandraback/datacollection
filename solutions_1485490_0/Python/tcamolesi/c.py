#!/usr/bin/python2

from sys import stdin

def at_pos(xs, p):
  i = 0
  while p - xs[i][0] >= 0:
    p -= xs[i][0]
    i += 1

    if i == len(xs):
      return None

  return (xs[i][0] - p, xs[i][1])

def t_after(xs, p):
  i = 0
  while p - xs[i][0] >= 0:
    p -= xs[i][0]
    i += 1

    if i == len(xs):
      return None

  return set(xs[j][1] for j in xrange(i, len(xs)))

def solve(a, b):
  max_score = 0

  q = [(0, 0, 0)]
  mq = 0
  while q:
    n = q[0]
    q = q[1:]

    s = (n[0], n[1])
    ta = at_pos(a, s[0])
    tb = at_pos(b, s[1])

    max_score = max(max_score, n[2])

    if not ta or not tb:
      continue

    if ta[1] == tb[1]:
      m = min(ta[0], tb[0])
      res = n[2] + m
      s = [(s[0] + m, s[1] + m, res)]
    else:
      keep_a = ta[1] in t_after(b, s[1])
      keep_b = tb[1] in t_after(a, s[0])

      l = []
      if keep_b:
        l.append((s[0] + ta[0], s[1], n[2]))

      if keep_a:
        l.append((s[0], s[1] + tb[0], n[2]))

      if not keep_a and not keep_b:
        l.append((s[0] + ta[0], s[1] + tb[0], n[2]))

      s = l

    q.extend(s)

  return max_score

n = int(stdin.readline())
for i in xrange(1, n+1):
  stdin.readline()
  l = [int(x) for x in stdin.readline().strip().split()]
  a = zip(l[::2], l[1::2])

  l = [int(x) for x in stdin.readline().strip().split()]
  b = zip(l[::2], l[1::2])

  res = solve(a, b)
  print 'Case #%d: %d' % (i, res)
