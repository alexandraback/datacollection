import heapq
from collections import defaultdict

def solve():
  line = raw_input()
  S = [int(n) for n in line.split()[1:]]
  total = sum(S)
  solution = []

  goal = total * 2 / len(S)
  needed = [max(0, goal - n) for n in S]
  total_needed = sum(needed)
  return [100.0*(n)/total_needed for n in needed]

def main():
  N = int(raw_input())
  for n in xrange(1, N+1):
    solution = solve()
    print "Case #%d: %s" % (n, ' '.join(str(d) for d in solution))

if __name__ == '__main__':
  main()
