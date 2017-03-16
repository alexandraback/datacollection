
T = input()
for t in range(T):
  row = raw_input().strip().split(' ')
  M = int(row[0])
  count = 0
  cur = int(row[1][0])
  for i in range(1, M + 1):
    # print i,count,cur
    if int(row[1][i]) == 0:
      continue
    if cur >= i:
      cur += int(row[1][i])
      continue
    count += i - cur
    cur += int(row[1][i]) + i - cur
  print 'Case #%d: %d' % (t + 1, count)
