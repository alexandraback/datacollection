import sys, math
N=16
J=50

def isprime(x):
  for i in range(2, long(math.ceil(math.sqrt(x)))):
    if x % i == 0:
      return i
  return 0
print "Case #1:"
res = 0
for i in range(1<<(N-2)):
  x = (i<<1) | (1<<(N-1)) | 1
  s = bin(x)[2:]
  jam = 1
  l = []
  for j in range(9):
    a = int(s, j+2)
    x = isprime(a)
    if x != 0:
      l.append(x)
    else:
      jam = 0
      break;
  if jam != 0:
    print s, ' '.join([str(kk) for kk in l])
    res += 1
    if res == J:
      break;
