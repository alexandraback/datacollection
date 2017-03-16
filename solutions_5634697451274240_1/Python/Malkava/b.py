T = int(raw_input())

case = 1
for case in xrange(1,T+1):
  stack = raw_input()
  res = 0
  for i in xrange(1, len(stack)):
    if stack[i] != stack[i-1]:
      res += 1
  if stack[-1] == '-':
    res += 1
  print("Case #%d: %d" % (case, res))



