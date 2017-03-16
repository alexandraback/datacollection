#coding=utf-8


def need(r,k):
  return 2*k*(k+1)+2*k*r-3*k


def sol(r,t):
  left, right = 0, 2*(10**18)
  ans = 0
  while left < right:
    mid = (right+left)/2
    ty = need(r, mid)
    if ty == t:
      return mid
    elif ty < t:
      left = mid+1
      ans = mid
    elif ty > t:
      right = mid-1
  if left == right:
    if need(r,left) <= t:
      return left
  return ans

T = int(raw_input())

for case in range(1, T+1):
  r,t = map(int, raw_input().split())
  ans = sol(r,t)
  print "Case #%d: %d"%(case, ans)
