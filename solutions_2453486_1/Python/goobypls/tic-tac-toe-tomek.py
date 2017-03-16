from sys import stdin
from collections import defaultdict

def get_state(board):
  scores = {c:defaultdict(int) for c in 'XO'}
  for i, line in enumerate(board):
    for j, char in enumerate(line):
      for p in scores:
        if char in p+'T':
          scores[p]['row'+str(i)] += 1
          scores[p]['col'+str(j)] += 1
          if i == j:
            scores[p]['ondiag'] += 1
          if i == 3-j:
            scores[p]['offdiag'] += 1
  mscores = [(max(d.values()), p) for p, d in scores.items() if d.values()] 

  if mscores and max(mscores)[0] == 4:
    return max(mscores)[1] + ' won'

  if '.' in ''.join(board):
    return "Game has not completed"

  return "Draw"


cases = int(stdin.readline().strip())
for i in range(cases):
  board = [stdin.readline().strip() for j in range(4)]
  print("Case #{}: {}".format(i+1, get_state(board)))
  stdin.readline()
