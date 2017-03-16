import sys

f = open(sys.argv[1], 'r')

T = int(f.readline())
for t in range(1, T + 1):
  print('Case #{0}:'.format(t), end = ' ')
  n = int(f.readline())
  d, h, m = [], [], []
  for i in range(n):
    hikers = [int(val) for val in f.readline().split()]
    d.append(hikers[0])
    h.append(hikers[1])
    m.append(hikers[2])

  hikers1 = ()
  hikers2 = ()
  if n == 1 :
    hikers1 = (d[0], h[0], m[0])
    hikers2 = (d[0] + 360, h[0], m[0] + 1)
  elif m[0] < m[1] :
    hikers1 = (d[0], h[0], m[0])
    hikers2 = (d[1], h[1], m[1])
  else :
    hikers2 = (d[0], h[0], m[0])
    hikers1 = (d[1], h[1], m[1])

  if (360 - hikers2[0]) * hikers2[2] / hikers1[2] >= 720 - hikers1[0] :
    print(1)
  else :
    print(0)
