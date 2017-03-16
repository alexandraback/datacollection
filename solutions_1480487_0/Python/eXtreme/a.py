import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  J = map(int, sys.stdin.readline().strip().split())
  del J[0]

  allScores = sum(J)

  minLev = 0.0
  maxLev = 1E6
  while maxLev - minLev > 1E-8:
    midLev = (minLev + maxLev) / 2

    added = 0
    for pts in J:
      if midLev > pts:
        added += midLev - pts

    if added >= allScores:
      maxLev = midLev
    else:
      minLev = midLev

  accLev = minLev

  print 'Case #%d:' % t,
  for pts in J:
    minVotes = 100.0 * max(0, accLev - pts) / allScores
    print minVotes,
  print ''
