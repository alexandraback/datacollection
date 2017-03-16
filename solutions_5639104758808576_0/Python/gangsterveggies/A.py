t = int(raw_input())

for i in range(t):
  line = raw_input().split()
  num = int(line[0])
  vals = line[1]

  ct = 0
  ans = 0
  for j in range(num + 1):
    if j > ct + ans:
      ans += j - (ct + ans)
    ct += int(vals[j])
  print "Case #%d: %d" % (i + 1, ans)
