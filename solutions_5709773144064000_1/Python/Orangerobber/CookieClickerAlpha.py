import sys

T = int(sys.stdin.readline().strip())
for trial in range(1, T+1):
  print 'Case #%d:' % trial,

  params = sys.stdin.readline().strip().split()
  c = float(params[0])
  f = float(params[1])
  x = float(params[2])

  rate = 2.0 
  farms = 0
  time = 0

  while((x-c)/(rate)>x/(rate+f)):
    time += c/rate
    farms += 1
    rate += f

  time += x/rate
  print '%.7f' % time
  
    