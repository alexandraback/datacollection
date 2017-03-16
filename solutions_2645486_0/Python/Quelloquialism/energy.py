T = input()
for i in range(1, T+1):
  E, R, N = [int(x) for x in raw_input().split(" ")]
  v = [int(x) for x in raw_input().split(" ")]
  lah = [0] * (E + 1)
  for j in v:
    neh = [0] * (E + 1)
    for k in range(E + 1):
      for a in range(k + 1):
        res = min(k - a + R, E)
        neh[res] = max(neh[res], lah[k] + a * j)
    lah = neh
  print "Case #" + str(i) + ":", max(lah)
