#coding=utf-8


T = int(raw_input())

for CASE in range(1, T+1):
  X, Y = map(int, raw_input().split())
  ans = ""
  if X < 0:
    ans+="EW"*(-X)
  else:
    ans+="WE"*X
  if Y < 0:
    ans+="NS"*(-Y)
  else:
    ans+="SN"*Y
  print "Case #%d: %s"%(CASE, ans)
