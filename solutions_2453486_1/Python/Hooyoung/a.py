#!/usr/bin/python

def ri():
  x = ""
  while not x:
    x = raw_input().strip()
  return x

def setwin(s,win):
  s = ''.join(s)
  if s.replace('T','X')=='XXXX':
    win[0] = True
  if s.replace('T','O')=='OOOO':
    win[1] = True

t = int(ri())
for i in xrange(t):
  a = list()
  win = [False,False]
  for j in xrange(4):
    a.append(ri())
    setwin(a[-1],win)
  for j in xrange(4):
    setwin((a[0][j],a[1][j],a[2][j],a[3][j]),win)
  setwin((a[0][0],a[1][1],a[2][2],a[3][3]),win)
  setwin((a[0][3],a[1][2],a[2][1],a[3][0]),win)
  out = ""
  if win[0]:
    out = "X won"
  elif win[1]:
    out = "O won"
  elif '.' in ''.join(a):
    out = "Game has not completed"
  else:
    out = "Draw"
  print "Case #%d:"%(i+1),out

    

