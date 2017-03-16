for testcase in xrange(input()):
  r, t = map(int, raw_input().split())
  start = (-3-2*r+(1-4*r+4*r*r+8*t)**0.5)/4 + 4
  def find(start,r,t):
    for x in xrange(int(start),-1,-1):
      if (1+x)*(1+2*r+2*x) <= t:
        return x+1
  circles = find(start,r,t)
  print "Case #%d: %d" % (testcase + 1, circles)
  testcase += 1
