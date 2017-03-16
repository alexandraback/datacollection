import heapq
from collections import defaultdict

def solve():
  line = raw_input()
  S = (int(n) for n in line.split()[1:])
  sums = []
  sets = defaultdict(list)
  for n in S:
    heapq.heappush(sums, n)
    sets[n] = [set([n])]
    
  while sums:
    asum = heapq.heappop(sums)
    for aset in sets[asum]:
      for bsum in sets.keys():
        if bsum == asum:
          continue
        for bset in sets[bsum]:
          if aset.isdisjoint(bset):
            newset = aset.union(bset)
            newsum = asum + bsum
            setswithnewsum = sets[newsum]

            for candidate in setswithnewsum:
              if candidate.isdisjoint(newset):
                print ' '.join(str(n) for n in newset)
                print ' '.join(str(n) for n in candidate)
                return
            setswithnewsum.append(newset)
    del sets[asum]

  print 'Impossible'

def main():
  N = int(raw_input())
  for n in xrange(1, N+1):
    print "Case #%d:" % n
    solve()

if __name__ == '__main__':
  main()
