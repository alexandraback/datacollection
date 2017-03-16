N = int(input())

for x in range(1, N+1):
  line = input().split()
  r = int(line[0])
  t = int(line[1])
  tmp = (2*r-1)/4.0
  y = int((t*.5+tmp*tmp)**.5 - tmp)
  while y*(2*y+2*r-1) <= t:
    y += 1
  while y*(2*y+2*r-1) > t:
    y -= 1
  print("Case #%d: %d" % (x, y))
