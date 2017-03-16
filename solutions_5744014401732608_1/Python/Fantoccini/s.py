from multiprocessing import Pool
from collections import defaultdict


def solve(line):
    res = ["POSSIBLE"]
    n, m = map(int, line.strip().split())
    if m > (1 << (n - 2)):
        return "IMPOSSIBLE"
    if m > 0:
        m -= 1
        res.append("0" + "1" * (n - 2) + "1")
    for i in xrange(n - 2):
        res.append("0" * (2 + i) + "1" * (n - 3 - i) + str(m % 2))
        m /= 2
    res.append("0" * n)
    return "\n".join(res)


p = Pool(8)
with open("in.txt", "r") as fin:
    results = p.map(solve, fin.readlines()[1:])
    with open("out.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res)))
