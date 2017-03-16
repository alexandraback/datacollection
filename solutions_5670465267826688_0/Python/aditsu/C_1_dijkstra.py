mult = [[1, 2, 3, 4], [2, -1, 4, -3], [3, -4, -1, 2], [4, 3, -2, -1]]
for i in range(input()):
  x = int(raw_input().split()[1])
  s = raw_input() * x
  p = 1
  g = 1
  j = 0
  ok = False
  while j < len(s):
    d = "1ijk".index(s[j])
    p = mult[p - 1][d]
    if p < 0:
      p = -p
      g = -g
    j+=1
    if p == 2 and g == 1:
      ok = True
      break
  if ok:
    ok = False
    p = 1
    g = 1
    while j < len(s):
      d = "1ijk".index(s[j])
      p = mult[p - 1][d]
      if p < 0:
        p = -p
        g = -g
      j+=1
      if p == 3 and g == 1:
        ok = True
        break
  if ok:
    p = 1
    g = 1
    while j < len(s):
      d = "1ijk".index(s[j])
      p = mult[p - 1][d]
      if p < 0:
        p = -p
        g = -g
      j+=1
    if p == 4 and g == 1:
      print "Case #" + str(i + 1) + ": YES"
      continue
  print "Case #" + str(i + 1) + ": NO"
