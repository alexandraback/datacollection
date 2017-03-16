from multiprocessing import Pool


def solve(n, cr):
    crs = cr.split("\n")
    m = {}
    mi = {}
    j = 0
    crn = []
    flag = set()
    for line in crs:
        nums = map(int, line.split())
        crn.append(nums)
    ms = -1
    for i in xrange(n):
        for j in xrange(2*n-1):
            if j in flag:
                continue
            if i not in mi:
                mi[i] = crn[j][i]
                m[i] = [j]
            elif mi[i] > crn[j][i]:
                mi[i] = crn[j][i]
                m[i] = [j]
            elif mi[i] == crn[j][i]:
                m[i].append(j)
        for idx in m[i]:
            flag.add(idx)
        if len(m[i]) == 1:
            ms = i
    res = []
    for i in xrange(n):
        if i == ms:
            res.append(str(crn[m[i][0]][i]))
        else:
            n0 = crn[m[i][0]][ms]
            n1 = crn[m[i][1]][ms]
            if n0 == crn[m[ms][0]][i]:
                res.append(str(n1))
            else:
                res.append(str(n0))
    return " ".join(res)


p = Pool(8)
pr = []
with open("in.txt", "r") as fin:
    t = int(fin.readline())
    for i in xrange(t):
        n = int(fin.readline())
        cr = ""
        for j in xrange(2 * n - 1):
            cr += fin.readline()
        pr.append(p.apply_async(solve, (n, cr)))
    p.close()
    p.join()
    with open("out.txt", "w") as fout:
        i = 0
        for res in pr:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res.get())))
