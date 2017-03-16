import sys

def join(x,N,S):
    if x > 0:
        #print (S+N)*x,
        sys.stdout.write((S+N)*x)
    elif x < 0:
        #print (N+S)*(-x),
        sys.stdout.write((N+S)*(-x))
    

ntest = int(raw_input())
for itc in range(ntest):
  print 'Case #%d:' % (itc+1),
  destX, destY = map(int, raw_input().split())
  join(destY,'N','S')
  join(destX,'E','W')
  print
 