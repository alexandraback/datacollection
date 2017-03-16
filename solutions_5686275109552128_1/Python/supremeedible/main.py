import sys
import math

def cdiv(a, b):
  if a % b == 0:
    return a / b - 1;
  else:
    return a / b;

T = int(sys.stdin.readline().rstrip('\n'))

for Q in range(1, T + 1):
  D = int(sys.stdin.readline().rstrip('\n'))
  plates = []
  line = sys.stdin.readline().rstrip('\n').split(' ')

  for p in [int(a) for a in line]:
    while p >= len(plates): plates.append(0)
    plates[p] = plates[p] + 1

  bestTime = len(plates) - 1
  remainingPileSize = 1

  for splitPilesOfSizeAtLeast in range(len(plates)):
    if plates[splitPilesOfSizeAtLeast]:
      for intoPilesOfSize in range(remainingPileSize, splitPilesOfSizeAtLeast):
        time = intoPilesOfSize
        for i in range(splitPilesOfSizeAtLeast, len(plates)):
          if plates[i]:
            time = time + plates[i] * cdiv(i, intoPilesOfSize)
            if time >= bestTime: break;
        else: bestTime = time

#        print 'split piles >= {} into {}: {}'.format(splitPilesOfSizeAtLeast, intoPilesOfSize, time)
#        if time < bestTime: bestTime = time

      remainingPileSize = splitPilesOfSizeAtLeast

  print 'Case #{}: {}'.format(Q, bestTime)
