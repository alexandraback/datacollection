for c in xrange(int(raw_input())):
  pointv = map(int, raw_input().split())[1:]
  totalling = sorted(pointv)[::-1]
  X = sum(pointv)
  mini = min(pointv[0], pointv[1])
  mins = max(pointv[0], pointv[1])
  ave = 2.0 * X / len(pointv)
  for i in xrange(len(pointv)):
    target = (X + sum(totalling[i:])) / (len(pointv) - i + 0.0)
    minvotes = []
    for i in pointv:
      if i<target:
        minvotes.append(target - i)
      else:
        minvotes.append(0)
    if sum(minvotes) - X < 0.00000001:
      break
  print "Case #"+str(c+1)+": "," ".join(map(lambda x: str((x*100.0)/X), minvotes))
