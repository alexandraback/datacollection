import sys

T=int(sys.stdin.readline().strip())

for t in range(1, T+1):
    N = int(sys.stdin.readline().strip())
    L = []
    for _ in range(2 * N - 1):
        L.append(list(map(int, sys.stdin.readline().strip().split())))

    H = []
    W = []

    used=set()

    missing=None
    pair=None
    for i in range(N):
        m = None
        a, b = None, None
        for j in range(len(L)):
            if j in used:
                continue
            if m is None or L[j][i] < m:
                a = j
                b = None
                m = L[j][i]
            elif L[j][i] == m:
                b = j
        
        H.append(L[a])
        if b == None:
            missing=i
            pair=L[a]
            W.append(None)
        else:
            W.append(L[b])
        used.add(a)
        used.add(b)

    ans=[]
    for j in range(N):
        if j == missing:
            ans.append(pair[j])
        else:
            if W[j][missing] == pair[j]:
                ans.append(H[j][missing])
            else:
                ans.append(W[j][missing])

    print("Case #%d: %s" % (t, " ".join(map(str, ans))))
