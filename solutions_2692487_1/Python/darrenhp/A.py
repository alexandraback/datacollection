#coding=utf-8



def solove(s, a):
  if s <= 1:
    return len(a)

  la = len(a)
  ops = 0
  ans = la 
  
  for i in range(la):
   # print "==", i, s, a[i]
    while s <= a[i]:
      s = s * 2 - 1
      ops = ops + 1
    s += a[i]
    if ans > ops + la - i - 1:
      ans = ops + la - i - 1
  return ans

T = int(raw_input())

for t in range(1, T+1):
  A, N = map(int, raw_input().split())
  a = map(int, raw_input().split())
  ans = solove(A, sorted(a))
  print "Case #%d: %d"%(t, ans)


