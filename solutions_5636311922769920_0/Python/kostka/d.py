def test():
  [k,c,s] = list(map(int,input().split(" ")))
  return " ".join(map(str,range(1,k+1)))


t = int(input())

for ttt in range(1,t+1):
  print("Case #"+str(ttt)+":", test())
