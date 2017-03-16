for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  D = input()
  cakes = map(int, raw_input().split(" "))
  assert D == len(cakes)
  ans = 1e100
  height = 1
  while 1:
    add = 0
    for cake in cakes:
      add += (cake-1)//height
    ans = min(ans, height+add)
    if add == 0:
      break
    height += 1
  print ans
