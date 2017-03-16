t = int(raw_input())
for i in xrange(1, t + 1):
    n = int(raw_input())
    S, A, B = [], [], []
    for j in xrange(n):
        s = raw_input()
        a, b = s.split()
        S.append(s)
        A.append(a)
        B.append(b)
    def find(l, v):
        res = []
        for j in range(len(l)):
            if l[j] == v:
                res.append(j)
        return res
    res = 0
    for j, s in enumerate(S):
        a, b = s.split()
        a_find = find(A, a)
        a_find.remove(j)
        b_find = find(B, b)
        b_find.remove(j)
        if a_find and b_find:
            res += 1
    print "Case #{}: {}".format(i, res)
