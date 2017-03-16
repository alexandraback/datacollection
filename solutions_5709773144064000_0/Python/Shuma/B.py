from itertools import count, izip, imap
for T in xrange(1, input() + 1):
    C, F, X = map(float, raw_input().split())
    def sn(i):
        return 2 + F * i
    cache = {0: 0, 1:C / 2}
    def tn(i):
        if i in cache:
            return cache[i]
        cache[i] = tn(i - 1) + C / sn(i - 1)
        return cache[i]
    def un(i):
        return tn(i) + X / sn(i)
    for a, b in izip(imap(un, count(0)), imap(un, count(1))):
        if a < b:
            print "Case #{0}: {1:.7f}".format(T, a)
            break
        
        
        
