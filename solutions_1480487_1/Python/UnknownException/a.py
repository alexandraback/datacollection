'''
Created on May 5, 2012

@author: Indra
'''
import sys, os

#filename = "A-large"
filename = "A-large"

path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".in"))
reader = open(path, "rb")
path = os.path.normpath(os.path.join(os.path.dirname(__file__), filename + ".out"))
writer = open(path, "w")
svotes = []
X = 0
T = int(reader.readline().rstrip())

def getBestMin(curvote, dough):
    i = 0
    tcnt = 0
    while dough > 0 and i < len(svotes):
        low, lcnt = svotes[i]
        if curvote == low: lcnt -= 1
        tcnt += lcnt
        if len(svotes) > i + 1:
            next = svotes[i + 1][0]
            gap = (next - low) * tcnt
            if gap <= dough:
                dough -= gap
                i += 1
                continue
            else:
                return low + (float(dough) / float(tcnt))
        else:
            return low + (float(dough) / float(tcnt)   )

def getRet(curvote):
    lo = 0.0
    hi = 1.0
    while hi - lo > 1e-8:
        c = (hi + lo) / 2.0
        score = curvote + c * X
        best = getBestMin(curvote, (1.0 - c) * X)
#        print curvote,",",c,"::",score,"   ",best
        if(score >= best):
            hi = c
        else:
            lo = c
    return lo
caseno = 1
while caseno <= T:
    line = reader.readline().rstrip()
    t = [int(x) for x in line.split(' ')]
    N = t[0]
    votes = t[1:]
    tdict = {}
    for vote in votes:
        if tdict.has_key(vote):
            tdict[vote] += 1
        else:
            tdict[vote] = 1
    
    svotes = []
    for vp in sorted(tdict.iteritems()):
        svotes.append(vp)
    #svotes.reverse()
    print "fdklj", svotes
    X = 0
    for vote in votes:
        X += vote
    
    ret = [getRet(vote) for vote in votes]
    pret = ' '.join(str(100*x) for x in ret)
    print N, ":::", votes, "===", pret
    
    
    writer.write("Case #%s: %s\n" % (str(caseno), pret))
    caseno += 1

writer.close()
