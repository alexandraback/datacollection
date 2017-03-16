import sys
ip = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""
op = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""
mp = {}
for x in xrange(len(ip)):
  if mp.get(ip[x]):
    assert mp[ ip[x] ] == op[x], "Must be same"
  mp[ ip[x] ] = op[x]
mp['z'] = 'q'
mp['q'] = 'z'
for line in sys.stdin:
  cases, c = int(line), 1
  for line in sys.stdin:
    print "Case #%d: %s" % (c, ''.join(mp.get(j, j) for j in line)[:-1])
    c += 1
  break

