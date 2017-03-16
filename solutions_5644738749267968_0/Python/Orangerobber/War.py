import sys

T = int(sys.stdin.readline().strip())

for trial in range(1, T+1):
  print 'Case #%d:' % trial,
  N = int(sys.stdin.readline().strip())
  w = sys.stdin.readline().strip().split()
  naomi = sorted([float(x) for x in w],reverse=True)
  w = sys.stdin.readline().strip().split()
  ken = sorted([float(x) for x in w], reverse=True)

  nwins = 0
  k = list(ken)
  for b in naomi:
    if(b>max(k)):
      nwins+=1
    else:
      k.pop(0)

  dwins = 0

  while(len(naomi)>0):
    if(naomi[0]>max(ken)):
      dwins+=1
      naomi.pop(0)
      ken.pop(0)
    else:
      ken.pop(0)
      naomi.pop(-1)
  print dwins, nwins