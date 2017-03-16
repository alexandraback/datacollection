from collections import defaultdict

f = open('C-small-attempt1.in', 'r')
o = open('C.out', 'w')

inf = float('inf')

def find(l):
    c = 0
    fd = defaultdict(set)
    ld = defaultdict(set)
    for i, (fn, ln) in enumerate(l):
        f = []
        for o in fd[fn]:
            if len(ld[l[o][1]]) > 1:
                c += 1
                f.append(o)
        for o in f:
            fd[fn].remove(o)
            ld[l[o][1]].remove(o)
        f = []
        for o in ld[ln]:
            if len(fd[l[o][0]]) > 1:
                c += 1
                f.append(o)
        for o in f:
            ld[ln].remove(o)
            fd[l[o][0]].remove(o)
        fd[fn].add(i)
        ld[ln].add(i)
    return c

m = int(f.readline().strip())
i = 1

while i <= m:
    n = int(next(f).strip())
    l = []
    while n > 0:
        l.append(next(f).strip().split())
        n -= 1
    print('Case #{0}: {1}'.format(i, find(l)), file = o)
    i += 1

f.close()
o.close()
