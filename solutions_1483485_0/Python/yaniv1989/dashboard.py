import sys

def bt():
    s = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
    res = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"
    t = list("abcdefghijklmnopzrstuvwxyq")
    for a, b in zip(s, res):
        if a.isalpha():
            t[ord(a)-ord('a')] = b
    return ''.join(t)

rl = lambda: sys.stdin.readline().strip()
T = int(rl())
from string import maketrans
trantab = maketrans("abcdefghijklmnopqrstuvwxyz", bt())
for t in xrange(T):
    s = rl()
    print "Case #" + str(t+1) + ": " + s.translate(trantab)
