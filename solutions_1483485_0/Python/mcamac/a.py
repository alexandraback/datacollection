enc = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
dec = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

d = {}
d['z'] = 'q'
d['q'] = 'z'

for i in range(len(enc)):
  d[enc[i]] = dec[i]

f = open('a.in', 'r')
fo = open('asmall.out', 'w')
t = int(f.readline().strip())

for i in range(t):
  s = f.readline().strip()
  ss = ""
  for c in s:
    ss += d[c]
  fo.write("Case #%d: %s\n" % (i+1, ss) )