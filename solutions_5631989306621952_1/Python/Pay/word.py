ti = 0
tn = input()
while ti < tn:

  s = raw_input()
  a = s[0]
  s = s[1:]

  for x in s:
    if a[0] <= x:
      a = x + a
    else:
      a = a + x

  print 'Case #%s: %s' % (ti + 1, a)
  ti += 1
