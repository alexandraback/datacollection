from multiprocessing import Process, Manager

mod = 1000000007
fact_mem = [1]
def fact(n):
    while n >= len(fact_mem):
        fact_mem.append(fact_mem[-1] * len(fact_mem) % mod)
    return fact_mem[n]

def func(ci, res, n, l):
    res[ci] = 0
    s = {}
    e = {}
    m = {}
    c = {}
    for i in xrange(n):
        si = l[i]
        for ch in xrange(97, 123):
            char = chr(ch)
            if char in si:
                li = si.find(char)
                ri = si.rfind(char)
                if si.count(char) != ri - li + 1:
                    return
                if char != si[0] and char != si[-1]:
                    m[char] = m.get(char, 0) + 1
                    if m[char] > 1:
                        return 
        s[i] = si[0]
        e[i] = si[-1]
        c[i] = 1
    for k, v in m.items():
        if v == 0:
            continue
        for i in xrange(n):
            if s[i] == k or e[i] == k:
                return
    res[ci] = 1
    ind = {}
    for ch in xrange(97, 123):
        char = chr(ch)
        cnt = 0
        for k in s.keys():
            if s[k] == char and e[k] == char:
                ind[char] = True
                cnt += 1 
                s.pop(k)
                e.pop(k)
        res[ci] *= fact(cnt)
        res[ci] %= mod
    for ch in xrange(97, 123):
        char = chr(ch)
        si = -1
        ei = -1
        for k in s.keys():
            if s[k] == char:
                ind[char] = False
                if si == -1:
                    si = k
                else:
                    res[ci] = 0
                    return
            if e[k] == char:
                ind[char] = False
                if ei == -1:
                    ei = k
                else:
                    res[ci] = 0
                    return
        if si >= 0 and ei >= 0 and si != ei:
            s[si] = s.pop(ei)
            e.pop(ei)
            c[si] += c.pop(ei)
            if ind[char]:
                c[si] -= 1
    idcnt = 0
    for k in ind:
        if ind[k]:
            idcnt += 1
    res[ci] *= fact(len(s) + idcnt)
    res[ci] %= mod
    for k in s.keys():
        if s[k] == e[k]:
            res[ci] *= c[k]
            res[ci] %= mod
    
if __name__ == "__main__":
    ps = []
    manager = Manager()
    fin = open("rtc.in", "r")
    fout = open("rtc.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in xrange(t):
        n = int(fin.readline())
        l = fin.readline().strip().split()
        process = Process(target=func, args=(ci, res, n, l))
        ps.append(process)
        process.start()
    for ci in xrange(t):
        ps[ci].join()
        fout.write("Case #%d: %s\n" % (ci + 1, str(res[ci])))
    fout.close()
    fin.close()
