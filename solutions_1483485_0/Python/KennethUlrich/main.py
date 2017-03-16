import sys

text = {"ejp mysljylc kd kxveddknmc re jsicpdrysi" : "our language is impossible to understand",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" : "there are twenty six factorial possibilities",
"de kr kd eoya kw aej tysr re ujdr lkgc jv" : "so it is okay if you want to just give up",
"q" : "z", "z" : "q"}

map = dict(zip("".join(text.keys()), "".join(text.values())))

sys.stdin.readline()
for tc, line in enumerate(sys.stdin):
    result = "".join([map[c] for c in line.strip()])
    print "Case #%d: %s" % (tc + 1, result)
    
    
    