import sys

D = [
      (0, "ZERO", 'Z'),
      (6, "SIX", 'X'),
      (2, "TWO", 'W'),
      (8, "EIGHT", 'G'),
      (3, "THREE", 'H'),
      (4, "FOUR", 'R'),
      (5, "FIVE", 'F'),
      (7, "SEVEN", 'V'),
      (1, "ONE", 'O'),
      (9, "NINE", 'I'),
    ]

def check():
  for i in range(len(D)):
    letter = D[i][2]
    for j in range(i + 1, len(D)):
      if letter in D[j][1]:
        sys.exit(1)

tc = int(input())
for cc in range(1, tc + 1):
  s = input()
  cnt = [0] * 26
  for c in s:
    cnt[ord(c) - ord('A')] += 1
  res = []
  for d in D:
    num = cnt[ord(d[2]) - ord('A')]
    for i in range(num):
      res.append(d[0])
    for c in  d[1]:
      cnt[ord(c) - ord('A')] -= num
  print('Case #%d:' % cc, end=' ')
  print(*sorted(res), sep='')
