T = int(raw_input())

for _ in range(T):
    E,R,N = [int(n) for n in raw_input().split(" ")]
    val = [int(n) for n in raw_input().split(" ")]
    G = [0]*(E+1)
    for i in range(N):
        lastG = G[::]
        pos = [0]*(E+1)
        for j in range(min(R,E),E+1):
            m = 0
            for k in range(max(0,j-R),E+1):
                if m < min((k-j+R),E)*val[i] + lastG[k]:
                    m = min((k-j+R),E)*val[i] + lastG[k]
                    pos[j] = k
            G[j] = m
    print "Case #%d: %d" % (_+1,max(G))
