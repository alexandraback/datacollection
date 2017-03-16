import sys

inf = sys.argv[1]

f = open(inf, 'rU')
outf = open(inf + ".out", 'w')

T = int(f.readline())
for t in xrange(T):
    N = int(f.readline())

    digits = []
    for i in xrange(2*N - 1):
        digits.extend([int(x) for x in f.readline().split()])

    counts = {}
    for c in digits:
        counts[c] = counts.get(c, 0) + 1

    found = []
    for key in counts:
        if counts[key] % 2 == 1:
            found.append(key)

    found = sorted(found)
    outf.write("Case #{0}: {1}\n".format(t+1, " ".join([str(x) for x in found])))


f.close()
outf.close()
