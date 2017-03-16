import sys

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

T = int(f.readline())
for t in xrange(T):
    (J, P, S, K) = (int(x) for x in f.readline().split())

    counts = {}

    total = 0
    out = ""
    for j in xrange(1, J+1):
        for p in xrange(1, P+1):
            for s in xrange(1, S+1):
                a = (j, p, 0)
                b = (0, j, s)
                c = (p, 0, s)
                ca = counts.get(a, 0)
                cb = counts.get(b, 0)
                cc = counts.get(c, 0)
                if ca == K or cb == K or cc == K:
                    continue
                counts[a] = ca + 1
                counts[b] = cb + 1
                counts[c] = cc + 1
                out += "{0} {1} {2}\n".format(j, p, s)
                total += 1

    outf.write("Case #{0}: {1}\n{2}".format(t+1, total, out))


f.close()
outf.close()
