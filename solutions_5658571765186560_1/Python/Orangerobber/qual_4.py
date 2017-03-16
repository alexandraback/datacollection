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

  if(X>6):
    rich(t)
    continue

  #print "Problem: ", X, R, C
  if not(R*C % X == 0):
    rich(t)
    continue

  if(X==1):
    gab(t)
    continue

  if(X==2):
    gab(t)
    continue

  if(R < (X+1)/2) or (C < X):
    rich(t)
    continue

  if(X == 3):
    gab(t)
    continue

  if(R==(X+1)/2):
    # generally problematic for x = 4,5,6
    #in the case of 4 and 6, any length will be an issue
    if(X==4) or (X==6):
        rich(t)
        continue
    else:
        if(C == 5):
            rich(t)
            continue
        else:
            gab(t)
            continue
  gab(t)

