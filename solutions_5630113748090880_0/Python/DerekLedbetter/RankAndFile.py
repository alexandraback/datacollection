#!/usr/bin/env python3
import collections

T = int(input().strip())

for caseNo in range(1, T + 1):
   N = int(input().strip())
   assert N > 0
   counter = collections.Counter()
   for _ in range(2 * N - 1):
      line = [ int(x) for x in input().split() ]
      assert len(line) == N
      counter.update(line)

   answer = [ x for x, c in counter.items() if c % 2 ]
   answer.sort()

   print('Case #{}: {}'.format(caseNo, ' '.join(str(x) for x in answer)))
