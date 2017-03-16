import sys

a = "z y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
b = "q a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

d = {}
for x, y in zip(a, b):
    d[x] = y


data = sys.stdin.readlines()
#n = int(data[0])
#print n
i = 1
for s in data[1:]:
    r = ''
    for t in s.strip():
        r += d[t]
    print "Case #%d: %s" % (i, r)
    i += 1
