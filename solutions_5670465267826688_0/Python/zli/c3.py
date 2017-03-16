import sys

def neg(v):
    return "-"+v if v[0]!="-" else v[1]

transition = {"1":{"i":"i", "j":"j", "k":"k"},
               "i":{"i":"-1", "j":"k", "k":"-j"},
               "j":{"i":"-k", "j":"-1", "k":"i"},
               "k":{"i":"j", "j":"-i", "k":"-1"}}
for c, trans in transition.items():
    transition["-"+c] = dict((k, neg(v)) for k,v in trans.items())
#print transition.keys()

def fulltrans(c1, c2):
    if c2 in "ijk":
        return transition[c1][c2]
    elif c2 == "1":
        return c1
    elif c2 == "-1":
        return neg(c1)
    else:
        return transition[neg(c1)][neg(c2)]

def leftinv(c):
    if c == "1":
        return c
    else:
        return neg(c)

def eval(f, L, X):
    reacheables = {}
    cur = "1"
    singlepass = "1"
    tofind = "ijk_"
    found = 0
    startpos = f.tell()
    for mult in xrange(X):
        f.seek(startpos)
        for i in xrange(L):
            c = f.read(1)
            cur = transition[cur][c]
            singlepass = transition[singlepass][c]
            reacheables[cur] = True
            if singlepass == tofind[found]:
                found += 1
                singlepass = "1"
    return reacheables, singlepass, found

f = open(sys.argv[1])
for case in xrange(int(f.readline())):
    print "Case #"+str(case+1)+":",
    L, Xorig = map(int, f.readline().strip().split())
    X = Xorig % 4
    Xorig = min(16 + (Xorig % 16), Xorig)
    #print L, Xorig
    #found, res = eval(L)
    reacheables, res, found = eval(f, L, Xorig)
    if found == 3 and res == "1":
        print "YES"
    else:
        print "NO"
    f.read(1)
