import math

magic = 1000000007

def dfs(data, i, n, v, s):
    if len(v) >= n:
        return 1

    fixed = False

    for j in xrange(n):
        if j in v: continue
        if data[i][-1] == data[j][0]:
            fixed = True
            break

    res = 0
    if fixed:
        for j in xrange(n):
            if j in v: continue
            if data[i][-1] == data[j][0]:
                v.add(j)
                s1 = []
                for ch in data[j]:
                    if ch not in s:
                        s1 += [ch]
                        s.add(ch)
                res += dfs(data, j, n, v, s)
                for ch in s1:
                    s.remove(ch)
                v.remove(j)
                if res >= magic:
                    res %= magic
    else:
        for j in xrange(n):
            if j in v: continue
            check = False
            for ch in data[j]:
                if ch in s:
                    check = True
                    break
            if check: continue
            v.add(j)
            s1 = set()
            for ch in data[j]:
                s1.add(ch)
            res += dfs(data, j, n, v, s.union(s1))
            v.remove(j)
            if res >= magic:
                res %= magic

    return res

with open('B-small-attempt6.in') as f:
    T = int(f.readline())

    for case in xrange(T):
        n = int(f.readline())

        data = [x for x in f.readline().split()]

        a = 0
        for i in range(n):
            chs = set()
            for t in data[i]:
                chs.add(t)
            a += dfs(data, i, n, set([i]), chs)
            if a >= magic:
                a %= magic

        print "Case #%d: %d" % (case+1, a)