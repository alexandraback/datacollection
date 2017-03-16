#!/usr/bin/python -tt

points = []

def pointsappend(x):
  if x[0]==0 and x[1]==0: return
  if x[0] == 0:
    tag = 'inf'
  else:
    tag = float(x[1])/float(x[0])

  if x[1]>=0 and x[0]>=0: sig=1
  elif x[1]>=0 and x[0]<0: sig=2
  elif x[1]<0 and x[0]<0: sig=3
  else: sig=4

  for j in points:
    if tag == j[2] and sig == j[3]: return

  points.append((x[0],x[1],tag,sig))
  return


def addpoint(x,y,w,h,D):
  for n in range(-D/h-1,D/h+1):
    for m in range(-D/w-1,D/w+1):
      if (x + 2*w*m)**2 + (y + 2*h*n)**2 <= D**2:
        pointsappend((x + 2*w*m, y + 2*h*n))
  return
  

def main(H,W,d,mat):
  for idx,j in enumerate(mat):
    if 'X' in j:
      mex=j.find('X')+1 
      mey=H-idx

  w = 2*(W-2)
  h = 2*(H-2)
  w1 = 2*mex - 3
  w2 = w-w1
  h1 = 2*mey - 3
  h2 = h - h1
  D = 2*d

  count = 0
  del points[:]

  #p0 (0,0)
  addpoint(0,0,w,h,D)
  #p1 (2*w2,0)
  addpoint(2*w2,0,w,h,D)
  #p2 (0,2*h2)
  addpoint(0,2*h2,w,h,D)
  #p3 (-2*w1,0)
  addpoint(-2*w1,0,w,h,D)
  #p4 (0,-2*h1)
  addpoint(0,-2*h1,w,h,D)

  #p5 (2*w2,2h2)
  addpoint(2*w2,2*h2,w,h,D)
  #p6 (2*w2,-2*h1)
  addpoint(2*w2,-2*h1,w,h,D)
  #p7 (-2*w1,2*h2)
  addpoint(-2*w1,2*h2,w,h,D)
  #p8 (-2*w1,-2*h1)
  addpoint(-2*w1,-2*h1,w,h,D)
   
  return len(points)


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    H,W,d = map(int,sys.stdin.readline().strip().split(" "))
    mat = []
    for j in xrange(H):
      mat.append(str(sys.stdin.readline().strip()))
    res = main(H,W,d,mat)
    print "Case #%d: %s" % (i + 1, res) 




