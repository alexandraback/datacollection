P = 1000000007
fact = [1]
for i in range(1, 200):
    fact.append(fact[-1] * i % P)

def count(n, ws):
    pi, pl, pr, pa = dict(), dict(), dict(), dict()
    for i, w in enumerate(ws):
        if w == w[0]*len(w):
            pa.setdefault(w[0], set()).add(i)
            continue
        if(w[0] == w[-1]):
            return 0
        if w[0] in pl or w[-1] in pr:
            return 0
        pl[w[0]] = i
        pr[w[-1]] = i
        i, j = 1, len(w)-2
        while w[i] == w[0]:
            i += 1
        while w[j] == w[-1]:
            j -= 1
        lst = w[0]
        for c in w[i:j+1]:
            if c != lst:
                if c == w[0] or c == w[-1] or c in pi:
                    return 0
                pi[c] = i
                lst = c
    for c in pi:
        if c in pl or c in pr or c in pa:
            return 0
    used = [False]*n
    cnt = 0
    res = 1
    for i in range(n):
        if ws[i] == ws[i][0]*len(ws[i]) or ws[i][0] in pr:
            continue
        if not used[i]:
            used[i] = True
        c = ws[i][0]
        if c in pa:
            for x in pa[c]:
                used[x] = True
            res *= fact[len(pa[c])]
            res %= P
        c = ws[i][-1]
        if c in pa:
            for x in pa[c]:
                used[x] = True
            res *= fact[len(pa[c])]
            res %= P
        while c in pl:
            if(used[pl[c]]):
                return 0
            used[pl[c]] = True
            c = ws[pl[c]][-1]
            if c in pa:
                for x in pa[c]:
                    used[x] = True
                res *= fact[len(pa[c])]
                res %= P
        cnt += 1
    for i in range(n):
        if not used[i]:
            if i in pa.get(ws[i][0], set()):
                for x in pa[ws[i][0]]:
                    used[x] = True
                res *= fact[len(pa[ws[i][0]])]
                res %= P
                cnt += 1
            else:
                return 0
    res *= fact[cnt]
    res %= P
    return res


t = int(raw_input())
for iCase in range(1, t+1):
    n = int(raw_input())
    w = raw_input().split()
    print 'Case #%d: %d' % (iCase, count(n, w))
