import sys

lines = []
with open(sys.argv[1]) as f:
    lines = f.readlines()

count = int(lines[0])

letter_map = dict(zip("ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvqz",
                      "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upzq"))

for x in xrange(1,count+1):
    s = lines[x][:-1]
    t = "".join(map(lambda x: letter_map[x], s))
    print "Case #%d: %s" % (x, t)
