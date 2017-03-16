TT = int(raw_input())
for tt in range(1, 1 + TT):
  K, C, S = map(int, raw_input().split())
  answer = []
  answer.append("Case #%d:" % tt)
  if S * C < K:
    answer.append("IMPOSSIBLE")
  else:
    for start in range(0, K, C):
      pos = 0
      for i, j in enumerate(range(start, min(start + C, K))):
        pos += j * (K ** i)
      answer.append(str(1 + pos))
  print " ".join(answer)
