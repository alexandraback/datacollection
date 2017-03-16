def test():
  s = input().split("+")
  res = 0
  for i in range(len(s)):
      if s[i] != "":
          res += 1 if i == 0 else 2
  return res


t = int(input())

for ttt in range(1,t+1):
  print("Case #"+str(ttt)+":", test())
