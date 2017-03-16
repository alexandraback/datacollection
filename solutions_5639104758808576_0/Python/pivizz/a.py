import sys

def solve(case):
  res = 0
  clap = 0
  for i, c in enumerate(case):
    n = int(c)
    if n == 0: continue
    if i > clap:
      res += i - clap
      clap = i
    clap += n
  return res

for caseIndex, case in enumerate(list(sys.stdin)[1:]):
  answer = solve(case.rstrip().split(' ')[1])
  print('Case #{0}: {1}'.format(caseIndex+1, answer))