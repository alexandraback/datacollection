import sys

T = int(sys.stdin.readline())

def gab(t):
    print "Case #%d: GABRIEL"%(t+1)

def rich(t):
    print "Case #%d: RICHARD"%(t+1)

for t in range(T):
  X, R, C = [int(x) for x in sys.stdin.readline().split()]
  if(R>C):
    #guarantee R < C
    tmp = R
    R = C
    C = tmp
  #print "Problem: ", X, R, C
  if not(R*C % X == 0):
    #print "Not multiple"
    rich(t)
    continue

  if(X==1):
    #print "X=1"
    gab(t)
    continue

  if(X==2):
    #print "Multiple, X=2"
    gab(t)
    continue

  if(R < (X+1)/2) or (C < X):
    #print "Won't fit"
    rich(t)
    continue

  if(X == 3):
    #print "Multiple, will fit, X=3"
    gab(t)
    continue

  if(R==2) and (C==4):
    #print "Won't fit, 2*4"
    rich(t)
    continue

  gab(t)
  #print "Should be fine"

