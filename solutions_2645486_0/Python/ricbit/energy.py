for t in xrange(1,1+input()):
  e,r,n = map(int, raw_input().split())
  v = map(int, raw_input().split())
  def search(points, start, pos):
    if pos >= n:
      return points
    m = 0
    for x in xrange(0, start + 1):
      m = max(m, search(x*v[pos]+points, min(e,start-x+r), pos+1))
    return m
  print "Case #%d: %d" % (t, search(0,e,0))
