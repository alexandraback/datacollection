from multiprocessing import Process, Manager

def gcd (p, q):
    if q == 0:
        return p
    else:
        return gcd(q, p % q)

def func(ci, res, p, q):
    res[ci] = "impossible"
    c = gcd(p, q)
    p, q = p / c, q / c
    if (q & (q - 1)) != 0:
        return
    res[ci] = 1
    while True:
        qq = 1 << res[ci]
        if p * qq >= q:
            return
        res[ci] += 1
    
    
if __name__ == "__main__":
    ps = []
    manager = Manager()
    fin = open("pe.in", "r")
    fout = open("pe.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in xrange(t):
        p, q = map(int, fin.readline().split("/"))
        process = Process(target=func, args=(ci, res, p, q))
        ps.append(process)
        process.start()
    for ci in xrange(t):
        ps[ci].join()
        fout.write("Case #%d: %s\n" % (ci + 1, str(res[ci])))
    fout.close()
    fin.close()
