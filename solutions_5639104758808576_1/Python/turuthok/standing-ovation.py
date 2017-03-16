cases = int(raw_input())
case_no = 1
for iter in xrange(cases):
  s = raw_input().split()[1]
  res, curr, n = 0, 0, len(s)
  for i in xrange(n):
    if (i > curr):
      res += i-curr;
      curr = i
    curr += ord(s[i]) - ord('0')
  print "Case #%d: %d" % (case_no, res)
  case_no += 1

