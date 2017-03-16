from fractions import Fraction as F

tot = None

mem = {}
def find(g, q):
    #print str(g)+" "+str(q)
    if (q > tot):
        return -1
    if (g > 40):
        return -1
    if (q + F(1,2**g) == tot):
        return g
    if ((g,q) in mem):
        return mem[(g,q)]
    prendo = find(g+1, q+F(1,2**g))
    #print "prendo "+str(prendo)
    if (prendo != -1):
        mem[(g,q)] = prendo
        return g
    mem[(g,q)] = find(g+1, q)
    #print "non prendo "+str(mem[(g,q)])
    return mem[(g,q)]

t = int(raw_input())
for k in range(t):
    f = raw_input()

    tot = F(f)
    d = tot.denominator
    if (not ((d & (d - 1)) == 0)):
        print "Case #"+str(k+1)+": impossible"
        continue
    if (d > 2**40):
        print "Case #"+str(k+1)+": impossible"
        continue

    #print "tot "+str(tot)
    if (tot==F(1,1)):
        print "Case #"+str(k+1)+": 1"
        continue
    mem = {}
    g = find(1,0)
    if (g==-1):
        print "Case #"+str(k+1)+": impossible"
    else:
        print "Case #"+str(k+1)+": "+str(g)
