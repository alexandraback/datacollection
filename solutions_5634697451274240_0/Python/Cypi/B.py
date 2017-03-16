_T = int(raw_input())
for _t in range(1, _T+1):

  s = raw_input()
  res = 0
  for i in range(len(s)-1):
    if s[i] != s[i+1]:
      res += 1
  if s[-1] == '-': res += 1

  print 'Case #{}: {}'.format(_t, res)
