#!/usr/bin/python
from sys import stdin, stderr

def solve(J, P, S, K):
  jacket_pants_pairs = []
  for i in range(J):
    for j in range(P):
      jacket_pants_pairs.append([K, (i, j)])
  result = []
  shirt_pants_used = {}
  shirt_jacket_used = {}
  used_set = set()
  for shirt_num in range(S):
    while True:
      jacket_pants_pairs = sorted(jacket_pants_pairs, reverse = True)
      for i, pair in enumerate(jacket_pants_pairs):
        num_left, (jacket, pants) = pair
        if shirt_pants_used.get((shirt_num, pants), 0) >= K:
          continue
        if shirt_jacket_used.get((shirt_num, jacket), 0) >= K:
          continue
        if (jacket, pants, shirt_num) in used_set:
          continue
        if num_left > 0:
          break
      else:
        break
      num_left, (jacket, pants) = jacket_pants_pairs.pop(i)
      jacket_pants_pairs.append([num_left - 1, (jacket, pants)])
      shirt_pants_used[(shirt_num, pants)] = shirt_pants_used.get((shirt_num, pants), 0) + 1
      shirt_jacket_used[(shirt_num, jacket)] = shirt_jacket_used.get((shirt_num, jacket), 0) + 1
      result.append([jacket + 1, pants + 1, shirt_num + 1])
      used_set.add((jacket, pants, shirt_num))

  out = ''
  out += str(len(result)) + '\n'
  out += '\n'.join(' '.join(str(x) for x in res) for res in result)
  return out

num_cases = int(stdin.readline())
for case_num in range(num_cases):
  J, P, S, K = [int(x) for x in stdin.readline().strip().split()]
  result = 'Case #{0}: {1}'.format(case_num + 1, solve(J, P, S, K))
  print result
  print >>stderr, result


'''
K = 2

3 3 3

1 1 1
1 1 2
1 2 1
1 2 2
1 3 3

2 1 1
2 1 2
2 2 1
2 2 2
2 3 3

3 1 3
3 2 3

xxx


1 1 = 0
1 2 = 0
1 3 = 0
2 1 = 0
2 2 = 0
2 3 = 0
3 1 = 0
3 2 = 1
3 3 = 1


1 1 1
1 1 2
1 2 1
1 2 2
1 3 1
1 3 2

2 1 3
2 2 3
2 3 3
2 1 1
2 2 1
2 3 1

3 1 2
3 1 3
3 2 2
3 2 3
'''
