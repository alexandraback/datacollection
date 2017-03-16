from multiprocessing import Pool


def im1(s):
    return int(s) - 1


def solve(n, line):
    f = map(im1, line.split())
    d = {}
    p = {}
    flag = set()
    for i in xrange(n):
        if f[i] not in d:
            d[f[i]] = 1
        else:
            d[f[i]] += 1
    print d
    while True:
        nd = -1
        for i in xrange(n):
            if i in flag:
                continue
            if i not in d or d[i] == 0:
                nd = i
                break
        if nd == -1:
            break
        flag.add(nd)
        d[f[nd]] -= 1
        p[f[nd]] = max(p.get(f[nd], 0), p.get(nd, 0) + 1)
    print d
    print f
    print flag
    print "p", p
    result = 0
    for node in xrange(n):
        if node in flag:
            continue
        c = set()
        pos = node
        m = 0
        m1 = 0
        while pos not in c:
            c.add(pos)
            flag.add(pos)
            if p.get(pos, 0) >= m:
                print ">", c, pos, m, m1
                m1 = m
                m = p.get(pos, 0)
            elif p.get(pos, 0) >= m1:
                m1 = p.get(pos, 0)
            pos = f[pos]
        if len(c) == 2:
            result = max(result, len(c) + m + m1)
        else:
            result = max(result, len(c))
        print c, m, m1
    return result


p = Pool(8)
with open("in.txt", "r") as fin:
    t = int(fin.readline())
    results = []
    for i in xrange(t):
        n = int(fin.readline())
        results.append(p.apply_async(solve, (n, fin.readline().strip())))
    p.close()
    p.join()
    with open("out.txt", "w") as fout:
        i = 0
        for res in results:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res.get())))
