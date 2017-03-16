#!/usr/bin/python

def ri():
  x = ""
  while not x:
    x = raw_input().strip()
  return x

t = int(ri())
for tt in xrange(t):
  n,m = map(int,ri().split())
  maxrow = list()
  maxcol = [0]*m
  a = list()
  for i in xrange(n):
    row = map(int,ri().split())
    a.append(row)
    maxrow.append(max(row))
    for j in xrange(m):
      maxcol[j] = max(maxcol[j],row[j])
  out = "YES"
  for i in xrange(n):
    for j in xrange(m):
      if a[i][j] != min(maxrow[i],maxcol[j]):
        out = "NO"
  print "Case #%d:"%(tt+1),out
      
    

 

  
