from sys import stdin

def prime(n):
  if n%2 == 0: return 2
  if n%3 == 0: return 3
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return f
    if n%(f+2) == 0: return f + 2
    f +=6
  return 0

def allprime(base2):
  temp = "{0:b}".format(base2)
  ret = ""
  for base in range(2, 11):
    r = prime(int(temp, base))
    if r == 0:
      return
    if ret:
      ret = ret + " "
    ret = ret + "%d" % (r)
  return ret

def doit(N, J):
  temp = '1'
  for cn in range(0, N-2):
    temp = temp + '0'
  temp = temp + '1'
  base2 = int(temp, 2)
  while J > 0:
    r = allprime(base2)
    if r:
      print "%s %s" % ("{0:b}".format(base2), r)
      J = J - 1
    base2 = base2 + 2

for cn in xrange(1,1+int(stdin.readline())):
  (N,J) = tuple(int(z) for z in stdin.readline().split())
  print "Case #%d:" % (cn)
  doit(N, J)
