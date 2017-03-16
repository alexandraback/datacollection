import sys

def divisor(i):  
  j = 2
  while j < 100000:
    if (i%j) == 0:
      return j
    j = j + 1
  return None

def chngbase(i, base):
  r = 0
  c = 1
  while i:
    if i&1:
      r += c
    i = i >> 1
    c = c * base
  return r

N=32
J=500
print "Case #1:"
c = (1<<(N-1))+1
stop = 1<<N
while c < stop:
  divs = []
  d = divisor(c);
  if not d:
    c = c + 2
    continue
  divs.append(d)
  for i in xrange(3, 11):
    d = divisor(chngbase(c, i));
    if not d:
      break
    divs.append(d)
    if (i == 10):
      print "{0:b} {1}".format(c, ' '.join(map(str, divs)))
      J = J - 1
      if (J == 0):
        sys.exit(0)
  c = c + 2

