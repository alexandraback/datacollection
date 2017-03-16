T = int(raw_input())

def tot_paint(r, nr):
  x = nr - 1
  return 2*(x+1)*r + x + 1 + 2 * x * (x+1)

def bsearch(t, imin, imax):  
  while imax >= imin:
      imid = (imax - imin)/2 + imin
      val = tot_paint(r, imid)
      if val < t:
        imin = imid + 1
      elif val > t:
        imax = imid - 1
      else:  
        return imid
  imid = imax
  while tot_paint(r, imid) <= t:
    imid = imid + 1
  return imid - 1

for case in range(1,T+1):
  r, t = map(int, raw_input().split())
  ncirc = bsearch(t, 1, t)
      
  print 'Case #' + str(case) + ': ' + str(ncirc)