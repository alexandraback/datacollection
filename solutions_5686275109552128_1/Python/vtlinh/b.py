import math

if __name__ == '__main__':
  with open('input') as fi:
    lines = fi.read().splitlines()

  tests = int(lines[0])
  for i in xrange(tests):
    ps = [int(j) for j in lines[2+i*2].split()]
    ma = max(ps)
    t = ma
    if t <= 3:
      print 'Case #%s: %s' %(i+1, t)
      continue

    for j in xrange(2,ma-1):
      ti = j
      for p in ps:
        if p <= j:
          continue
        ti += math.ceil(1.0*p/j)-1
      if ti < t:
        t = ti
         
    print 'Case #%s: %s' %(i+1, int(t))
