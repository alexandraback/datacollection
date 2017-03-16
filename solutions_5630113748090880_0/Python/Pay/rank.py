ti = 0
tn = input()
while ti < tn:

  n = input()
  a = {}

  for i in range(2 * n - 1):
    s = map(int, raw_input().split())
    if s != sorted(s): print 'Bug'

    for si in s:
      if not si in a: a[si] = 0
      a[si] += 1

  b = []
  for x in a:
    if a[x] % 2 != 0: b.append(x)

  c = ' '.join(str(x) for x in sorted(b))

  ti += 1
  print 'Case #%s: %s' % (ti, c)
