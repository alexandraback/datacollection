import sys
from collections import Counter
T = int(raw_input())

sys.setrecursionlimit(5000)


for t in xrange(T):
    scores = raw_input().split()

    def best(realC, realJ, cs, js): # assumes final realC > final realJ
      intC = int(realC or 0)
      intJ = int(realJ or 0)
      if len(cs) == 0:
        return (abs(intC - intJ), realC, realJ)

      if intC != intJ:
          c = cs[0]
          j = js[0]
          if c != '?' and j != '?':
            return best(realC + c, realJ + j, cs[1:], js[1:])
          elif c == '?' and j == '?':
            return best(realC + '0', realJ + '0', cs[1:], js[1:])
          elif c == '?':
            return best(realC + '0', realJ + j, cs[1:], js[1:])
          elif j == '?':
            return best(realC + c, realJ + '9', cs[1:], js[1:])

      c = cs[0]
      j = js[0]
      if c != '?' and j != '?':
        return best(realC + c, realJ + j, cs[1:], js[1:])
      elif c == '?' and j == '?':
        return min(
          best(realC + '0', realJ + '0', cs[1:], js[1:]),
          best(realC + '1', realJ + '0', cs[1:], js[1:]),
        )
      elif c == '?':
        return min(
          best(realC + j, realJ + j, cs[1:], js[1:]),
          best(realC + str((int(j) + 1) % 10), realJ + j, cs[1:], js[1:]),
        )
      elif j == '?':
        return min(
          best(realC + c, realJ + c, cs[1:], js[1:]),
          best(realC + c, realJ + str((int(c) + 9) % 10), cs[1:], js[1:]),
        )

    val1, realC, realJ = best('', '', scores[0], scores[1])
    ans2 = best('', '', scores[1], scores[0])
    if val1 > ans2[0]:
      realC = ans2[2]
      realJ = ans2[1]


    print 'Case #' + str(t + 1) + ': ' + realC + ' ' + realJ
