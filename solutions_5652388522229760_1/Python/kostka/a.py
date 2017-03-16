
def test():
  N = int(input())
  if N == 0:
    return "INSOMNIA"
  M = N
  S = set(str(M))
  while len(S) != 10:
    M += N
    for ele in list(str(M)):
      S.add(ele)
  return M


t = int(input())

for ttt in range(1,t+1):
  print("Case #"+str(ttt)+":", test())
