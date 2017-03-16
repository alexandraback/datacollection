#! /usr/bin/env python

def main():
  T = input()

  for n in xrange(T):
    N = input()
    t = []
    for i in xrange(N):
      a = map(int, raw_input().split())
      t.append(a)


    #print t
    print 'Case #%s: %s' % (n + 1, solve(t))

def solve(t):
  s = 0
  c = 0

  total = len(t)

  while 1:
    #print total, t, s, c

    if total == 0:
      return c

    y = [x for x in t if x[1] <= s]
    t = [x for x in t if x[1] > s]
    new_t = len(t)

    if new_t < total:
      s += len([x for x in y if len(x) == 2]) * 2 + len([x for x in y if len(x) == 3])
      c += total - new_t
      total = new_t
      continue

    max_l = None
    for l in t:
      if l[0] <= s:
        if max_l == None:
          max_l = l
        elif l[1] > max_l[1]:
          max_l = l

    if max_l == None:
      return 'Too Bad'
    else:
      s += 1
      c += 1
      max_l[0] = max_l[1]
      max_l.append(0)


main()
