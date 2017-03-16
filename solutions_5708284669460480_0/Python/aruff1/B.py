from collections import Counter
def kmp_table(W):
    if len(W)<=2: return [-1,0][:len(W)]
    T = [0]*len(W)
    pos = 2
    cnd = 0
    T[0] = -1
    T[1] = 0
    while pos < len(W):
        if W[pos-1] == W[cnd]:
            cnd += 1
            T[pos] = cnd
            pos += 1
        elif cnd>0:
            cnd = T[cnd]
        else:
            T[pos] = 0
            pos += 1
    return T
def prob_count(s,K,W):
    PC = {}
    W += '$'
    T = kmp_table(W)
    def pc(m=0,i=0):
        if (m,i) in PC: return PC[m,i]
        exp = i==len(W)-1
        if m+i==s: return exp 
        for c,p in K.items():
            M,I = m,i
            while 1:
                if W[I] == c:
                    exp+= p*pc(M,I + 1)
                    break
                elif T[I] > -1:
                    M = M + I - T[I]
                    I = T[I]
                else:
                    exp+= p*pc(M+1,0)
                    break
        PC[m,i] = exp
        return PC[m,i]
    return pc()
for t in xrange(input()):
    k,l,s = map(int,raw_input().split())
    K = dict(Counter(raw_input().strip()))
    K = {c:float(K[c])/k for c in K}
    L = raw_input().strip()
    x = min(i for i in xrange(1,l+1) if L.startswith(L[i:]))
    print "Case #%d: %.9f"%(t+1,((s-l+x)/x if set(L)-set(K)==set() else 0.0)-prob_count(s,K,L))
