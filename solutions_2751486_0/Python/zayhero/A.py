from collections import deque

x = ['a', 'e', 'i', 'o', 'u']

def chk(c):
  return c not in x

def cal(s, n):
  v = [0] * len(s)
  p = 0
  while p < len(s):
    if chk(s[p]):
      tmp = p
      while p < len(s) and chk(s[p]): p += 1
      for i in range(tmp, p - n + 1):
        v[i] = 1
    else:
      p += 1
  ans = 0
  sz = len(s)
  for i in range(sz - 1, -1, -1):
    if v[i]: sz = i
    if sz < len(s): ans += len(s) - sz - n + 1
  return ans

T = int(raw_input(""))
for i in range(1, T + 1):
  s, n = (elm for elm in raw_input("").split())
  n = int(n)
  res = cal(s, n)
  print 'Case #%d: %s' % (i, res)