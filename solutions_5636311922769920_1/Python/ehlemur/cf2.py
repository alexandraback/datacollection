T = input()

for _ in range(T):
  print 'Case #{}:'.format(_+1),
  k, c, s = map(int, raw_input().split())
  
  if s < (k + c - 1) / c:
    print 'IMPOSSIBLE'
    continue

  answer = []
  for i in range(s):
    path = range(i*c, (i+1)*c)
    for j in range(c):
      if path[j] >= k:
        path[j] = k - 1
    idx = 1
    power = 1
    for x in path[::-1]:
      idx += x * power
      power *= k
    answer.append(idx)
    if path[-1] == k - 1:
      break
  print ' '.join(map(str, answer))



