t = int(input())

def fil(remC, remJ, scoreC, scoreJ):
  if remC == 0 and remJ == 0:
    diff = int(scoreC) - int(scoreJ)
    return (abs(diff), int(scoreJ), scoreC, scoreJ)
  minA = (10000, 10000, '0', '0')
  for i in range(0, 10):
    if remC > 0:
      vys = 0
      for j in range(0, len(scoreC)):
        if scoreC[j] == '?':
          vys = j
          break
      res = fil(remC - 1, remJ, scoreC[:vys] + str(i) + scoreC[(vys + 1):], scoreJ)
      if abs(res[0]) < minA[0]:
        minA = res
      elif res[0] == minA[0] and res[1] < minA[1]:
        minA = res
    else:
      vys = 0
      for j in range(0, len(scoreJ)):
        if scoreJ[j] == '?':
          vys = j
          break
      res = fil(remC, remJ - 1, scoreC, scoreJ[:vys] + str(i) + scoreJ[(vys + 1):])
      if abs(res[0]) < minA[0]:
        minA = res
      elif res[0] == minA[0] and res[1] < minA[1]:
        minA = res
  return minA

for i in range(0, t):
  oc, jm = map(str, input().split())
  otC = 0
  otJ = 0
  for c in oc:
    if c == '?':
      otC += 1
  for c in jm:
    if c == '?':
      otJ += 1
  res = fil(otC, otJ, oc, jm)
  print("Case #" + str(i + 1) + ": " + res[2] + " " + res[3])