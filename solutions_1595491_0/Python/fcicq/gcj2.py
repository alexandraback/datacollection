import sys
data = sys.stdin.readlines()

cases = int(data[0])
for i in range(cases):
  d = data[i+1].split(' ')
  di = [int(j) for j in d]
  num = di[0]
  surprise = di[1]
  minnum = di[2]
  rd = sorted(di[3:], reverse=True)
  res = 0
  for j in rd:
    if j == 0 and minnum != 0: continue
    # 6,6,8
    if j % 3 == 0 and j >= minnum * 3 - 2:
      res += 1
    elif j % 3 == 0 and j >= minnum * 3 - 3:
      if surprise > 0:
        res += 1
        surprise -= 1
    # 6,7,7, 5,7,5
    elif j >= minnum * 3 - 2: # % 3 != 0
      res += 1
    elif j >= minnum * 3 - 4:
      if surprise > 0:
        res += 1
        surprise -= 1      
  print "Case #%d: %d" % (i+1, res)