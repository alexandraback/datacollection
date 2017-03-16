import sys

t = input()
for ii in range(1, t+1):
  sys.stdout.write('Case #');
  sys.stdout.write(str(ii));
  sys.stdout.write(': ')
  strin = raw_input()
  a = strin.split(' ')
  k = int(a[0])
  c = int(a[1])
  s = int(a[2])
  if (k > c * s):
    print "IMPOSSIBLE"
    continue
  num = 0
  while (num < k):
    tmp = 0
    for i in range(0, c):
      if (num < k):
        tmp = tmp * k + num
      else:
        tmp = tmp * k
      num = num + 1
    sys.stdout.write(str(tmp + 1))
    sys.stdout.write(' ')
  sys.stdout.write('\n')
      
