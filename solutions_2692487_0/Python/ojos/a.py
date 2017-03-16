from bisect import bisect_left
from math import ceil
from math import log

NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  A, N = [int(x) for x in raw_input().split()]
  others = [int(x) for x in raw_input().split()]

  if A == 1:
    print N
    continue

  result = 0
  others.sort()
  while True:
    pos = bisect_left(others, A);
    if pos == len(others):
      print result
      break
    if pos == 0:
      eaten, added = 0, 0
      tmpA = A
      tmpP = pos
      while (tmpA <= others[0]):
        tmpA += tmpA-1
        added += 1
      fail = 0
      while added >= eaten:
        if tmpP >= len(others):
          print result + len(others)
          fail = 1
          break
        now_eaten = bisect_left(others[tmpP:], tmpA)
        if now_eaten == 0:
          while (tmpA <= others[tmpP]):
            tmpA += tmpA-1
            added += 1
        else:
          eaten += now_eaten
          tmpA += sum(others[tmpP:tmpP+now_eaten])
          tmpP += now_eaten
      if fail == 1: break
      A = tmpA
      result += added
      others = others[tmpP:]
    else:
      A += sum(others[:pos])
      others = others[pos:]
