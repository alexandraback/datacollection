from sys import stdin

def score(N):
  target = [str(x) for x in range(10)]
  number = 0
  while target:
    number += N
    for digit in str(number):
      if digit in target:
        target.remove(digit)      
  return number


for case in xrange(1,1+int(stdin.readline())):
    N = int(stdin.readline().strip())
    print "Case #%d: %s" % (case, score(N) if N!=0 else "INSOMNIA")