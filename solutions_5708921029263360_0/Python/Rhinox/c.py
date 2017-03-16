# python 2.7

import os, sys

class Input:
    def __init__(self, fp): self.fp = fp
    def m(self, n, t=str):  return [map(t, list(self.line())) for i in range(n)]
    def ms(self, n, t=str, sep=' '):  return [map(t, self.line().split(sep)) for i in range(n)]
    def line(self):  return self.fp.readline().strip()
    def lines(self, n): return [self.fp.readline().strip() for x in range(n)]
    def words(self): return self.line().split()
    def int(self):   return int(self.line())
    def ints(self):  return map(int, self.words())
    def float(self): return float(self.line())
    def floats(self):return map(float, self.words())
    def str(self):   return self.line()
    def types(self, *types): return [t(w) for t,w in zip(types, self.words())]

if __name__ == "__main__":
    fn = "test.txt" if len(sys.argv) <= 1 else sys.argv[1]
    f = Input(open(fn))
    fout = open(os.path.splitext(fn)[0] + ".out", "w")

    import collections

    def verify(outfits, k):
        if len(set(outfits)) != len(outfits):
            print "same outfits twice"
            return False

        jp = collections.defaultdict(int)
        js = collections.defaultdict(int)
        ps = collections.defaultdict(int)
        def add(d, x):
            d[x] += 1
            return d[x] <= k

        #print outfits
        for j,p,s in outfits:
            if not add(jp, (j, p)): return 0
            if not add(js, (j, s)): return 1
            if not add(ps, (p, s)): return 2
        return True

    def write(o):
        if not isinstance(o, basestring): o = "%s"%o
        sys.stdout.write(o)
        fout.write(o)

    def writeln(s = ""):
        write("%s\n"%s)

    def spacedWrite(o):
        write(o); write(" ")

    def case(t, s=""):
        write("Case #%d: %s"%(t, s))

    def answer(t, ans):
        case(t)
        writeln("%s"%ans)

    def getOutfits(J, P, S, K):
        upperLimit = J * P * S

        jp = J * P
        limit = min(upperLimit, jp * K)

        outfits = []
        jp = collections.defaultdict(int)
        js = collections.defaultdict(int)
        ps = collections.defaultdict(int)
        of = set()

        for i in range(S):
            for j in range(1, J + 1):
                for p in range(1, P + 1):
                    s = 0
                    #print len(of)
                    while True:
                        s += 1
                        if (j, p, s) in of:
                            #print "of", j + p + s
                            continue
                        if js[j + s] >= K:
                            #print "js"
                            continue
                        if ps[p + s] >= K:
                            #print "ps"
                            continue
                        break
                    outfits.append((j, p, s))
                    jp[j + p] += 1
                    js[j + s] += 1
                    ps[p + s] += 1
                    of.add((j, p, s))
                    if len(outfits) >= limit: return outfits

    for T in range(f.int()):
        J, P, S, K = f.ints()
        outfits = getOutfits(J, P, S, K)

        if verify(outfits, K) is not True:
            print "ERR: ", J, P, S, K, "val: ", verify(outfits, K), outfits
            break

        case(T + 1)
        writeln(len(outfits))
        for outfit in outfits:
            writeln("%s %s %s"%outfit)

        #if T == 4: break