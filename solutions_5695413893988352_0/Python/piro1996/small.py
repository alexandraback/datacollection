N = input()

for n in range(N):
    a, b = raw_input().split()

    def dfs(p, q):
        res = (10 ** 30, p, q)
        if '?' in p:
            for c in '0123456789':
                r = dfs(p.replace('?', c, 1), q)
                if r[0] < res[0]:
                    res = r
        elif '?' in q:
            for c in '0123456789':
                r = dfs(p, q.replace('?', c, 1))
                if r[0] < res[0]:
                    res = r
        else:
            return (abs(int(p) - int(q)), p, q)
        return res
    
    res = dfs(a, b)
    print 'Case #%d: %s %s' % (n + 1, res[1], res[2])

