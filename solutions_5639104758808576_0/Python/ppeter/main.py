__author__ = 'Peter'
with open("A-small-attempt0.in","r") as inF:
    nt= int(inF.readline())
    for t in xrange(nt):
        n, seq= inF.readline().split()
        n=int(n)
        erg=0
        standing=0
        for i in xrange(n+1):
            while i>standing:
                erg+=1
                standing+=1
            standing+=int(seq[i])
        print "Case #%d: %d"%(t+1,erg)
