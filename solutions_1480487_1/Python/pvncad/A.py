import sys


import sys

T = int(sys.stdin.readline())

for caseno in xrange(T):
    line = sys.stdin.readline().strip()    
    ints = map(lambda x: int(x), line.split(' '))
    N = ints[0]
    total = sum(ints[1:]) + 0.0
    points = ints[1:]
    sorted_points = sorted(points, reverse=True)
    avg_points = 2.0/N
    rest = 1.0
    for i in xrange(len(sorted_points)):
      fraction = sorted_points[i]/total
      mp = (rest + 1) / (N -i)
      if fraction <= mp:
	break
      #print "%f, %f" % (mp, fraction)
      
      rest -= fraction
      avg_points = (rest+ 1)/ (N - i -1)
    
    votes = [ ]
    for p in points:
      fraction = p / total
      
      vote = max(0, avg_points - fraction)
      votes.append(str(vote * 100))
    print "Case #%d: %s" % (caseno+1, " ".join(votes))
    