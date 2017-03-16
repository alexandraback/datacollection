cases = int(raw_input().strip())
for x in range(1, cases+1):
  data = raw_input().strip().split()
  n = int(data[0])
  s = int(data[1])
  p = int(data[2])

  num = 0

  for q in range(3, 3+n):
    t = int(data[q])
    r = t - p
    if r < 0:
      continue
    if r >= (p-1)*2:
      num += 1
    elif r >= (p-2)*2 and s > 0:
      num += 1
      s -= 1

  print "Case #" + str(x) + ": " + str(num)
