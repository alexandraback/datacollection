# -*- coding: utf-8 -*-

def calc(A, V, n):
    while min(V) < A:
        for d in V[:]:
            if A > d:
                A += d
                del V[V.index(d)]
        if len(V) == 0:
            return n
    if len(V) == 1:
        return n+1
    Vb = V[:]
    Vb.remove(max(Vb))
    res1 = calc(A, Vb, n+1)
    if (A > 1):
        A *= 2
        A -= 1
        res2 = calc(A, V, n+1)
        return min(res1, res2)
    return res1

if __name__ == "__main__":
    s = open(input(), "r")
    count = int(s.readline())
    f=open("outputA.txt", "w")
    result = []
    for i in range(1, count+1):
        res = 0
        st = s.readline().split()
        A = int(st[0])
        N = int(st[0])
        V = list(map(int, s.readline().split()))
        res = calc(A, V, 0)
        result.append("Case #"+str(i)+": "+str(res)+"\n")
    f.writelines(result)
    f.close()
