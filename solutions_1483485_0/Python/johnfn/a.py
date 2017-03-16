enc =   """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jvyeq"""

plain = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give upaoz"""

mapping = {}
mapping['z'] = 'q'
for i, e_ch in enumerate(enc):
  p_ch = plain[i]
  mapping[e_ch] = p_ch

lines = [l[:-1] for l in open("in3")][1:]

for i, l in enumerate(lines):
  print "Case #%d:" % (i+1),
  res = ""
  for ch in l:
    res += mapping[ch]
  print res
