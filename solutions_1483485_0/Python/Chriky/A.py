import sys

code = """ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
y qee z"""

english = """our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
a zoo q"""

D = {c: e for c, e in zip(code, english)}

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    message = f.readline().strip()
    #print sorted(set(english))
    print "Case #%d:" % (t + 1), "".join([D[c] for c in message])
