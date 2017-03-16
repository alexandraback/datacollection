import sys

code = "qzejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
plain = "zqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"

mapping = {}
mapping[' '] = ' '
for i in range(len(code)):
  if code[i] != ' ':
    mapping[code[i]] = plain[i]

T = int(raw_input())
case = 0
for x in sys.stdin.readlines():
  case += 1
  trans = ""
  for i in range(len(x)):
    if x[i] != '\n':
      trans += mapping[x[i]]
  print "Case #%d: %s" % (case, trans)