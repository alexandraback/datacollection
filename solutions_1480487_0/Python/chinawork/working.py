import sys, re, os

N = int(sys.stdin.readline().strip())
for qw in range(1, N+1):
  print 'Case #%d:' % qw,

  values = [int(i.strip()) for i in sys.stdin.readline().split()]
  nContest = values[0]
  total = sum(values[1:])
  avg = float(total * 2) / nContest
  noneed = [i - avg for i in values[1:]]
  member = []
  for i in xrange(1, nContest + 1):
      if (noneed[i - 1] < 0):
          
          member.append(i)
  newtotal = 0
  for i in member:
      newtotal += values[i]
  newtotal += total
  newavg = float(newtotal) / len(member)
 # print newavg
 # print newavg, member
  for i in xrange(1, nContest + 1):
      if (values[i] >= avg):
          print float(0),
      else:
          percentage = float(newavg - values[i]) / total
          print "%.6f" % (percentage * 100),
  print
