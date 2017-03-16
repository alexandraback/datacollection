from multiprocessing import Pool
from collections import defaultdict


def solve(line):
    res = []
    print line
    J, P, S, K = map(int, line.strip().split())
    k = defaultdict(lambda: 0)
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(S):
                if k[(j, p, -1)] < K and k[(j, -1, s)] < K and k[(-1, p, s)] < K:
                    res.append(str(j + 1) + " " + str(p + 1) + " " + str(s + 1))
                    k[(j, p, -1)] += 1
                    k[(j, -1, s)] += 1
                    k[(-1, p, s)] += 1
    return str(len(res)) + "\n" + "\n".join(res)

p = Pool(8)
with open("in.txt", "r") as fin:
    results = p.map(solve, fin.readlines()[1:])
    with open("out.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res)))
