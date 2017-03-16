T = input()
for tc in range(1, T+1):
  A, N = [int(x) for x in raw_input().split(" ")]
  m = [int(x) for x in raw_input().split(" ")]
  m.sort()
  bmv = N
  if A == 1:
    print "Case #" + str(tc) + ":", bmv
    continue
  for rem in range(N + 1):
    mv = rem
    cA = A
    for i in range(N - rem):
      while cA <= m[i]:
        cA += cA - 1
        mv += 1
      cA += m[i]
    bmv = min(bmv, mv)
  print "Case #" + str(tc) + ":", bmv