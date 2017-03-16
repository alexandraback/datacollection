for tc in range(1, input() + 1):
  s = raw_input()
  res = s[0]
  for c in s[1:]:
    res = (c + res) if (c >= res[0]) else res + c
  print "Case #" + str(tc) +": " +str(res)