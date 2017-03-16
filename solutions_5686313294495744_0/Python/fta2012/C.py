import sys
from collections import defaultdict, Counter
T = int(raw_input())

sys.setrecursionlimit(5000)


for t in xrange(T):
    n = int(raw_input())
    ids1 = defaultdict(lambda: len(ids1))
    ids2 = defaultdict(lambda: len(ids2))
    words = []
    for i in xrange(n):
      word = raw_input().split()
      words.append((ids1[word[0]], ids2[word[1]]))

    def numCheaters(l):
      seen1 = set()
      seen2 = set()
      cheats = 0
      for (w1, w2) in l:
        if w1 in seen1 and w2 in seen2:
          cheats += 1
        seen1.add(w1)
        seen2.add(w2)
      return cheats
      
    ordered = []
    best = 0
    for x in words:
      topL = ordered + [x]
      top = numCheaters(topL)
      bottomL = [x] + ordered
      bottom = numCheaters(bottomL)

      if top > bottom:
        ordered = topL
      else:
        ordered = bottomL

      best = max(best, max(top, bottom))
      
    print 'Case #' + str(t + 1) + ': ' + str(best)
