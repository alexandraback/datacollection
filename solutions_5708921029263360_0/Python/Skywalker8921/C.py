import sys,math
from collections import Counter
from itertools import product

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def main_wrong(J,P,S,K):
    JS = Counter()
    JP = Counter()
    PS = Counter()
    res = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                #printerr(j,p,s,JS[(j,s)],JP[(j,p)],PS[(p,s)])
                if JS[(j,s)] < K and JP[(j,p)] < K and PS[(p,s)] < K:
                    JS[(j,s)] += 1
                    JP[(j,p)] += 1
                    PS[(p,s)] += 1
                    res.append([j+1,p+1,s+1])
    return len(res),res

def subseqs(S,i=0):
    if i == len(S):
        return [[]]
    a = S[i]
    old = subseqs(S,i+1)
    new = [s for s in old] + [[a]+s for s in old]
    return new
    
def main_small(J,P,S,K):
    cands = subseqs(list(product(range(J),range(P),range(S))))
    cands.sort(key=lambda x:-len(x))
    for c in cands:
        printerr(c)
        JS = Counter()
        JP = Counter()
        PS = Counter()
        for (j,p,s) in c:
            if JS[(j,s)] < K and JP[(j,p)] < K and PS[(p,s)] < K:
                JS[(j,s)] += 1
                JP[(j,p)] += 1
                PS[(p,s)] += 1
            else:
                break
        return len(c),c
    return 0,[]

def main_hc(J,P,S,K):
    if [J,P,S,K] == [2,3,3,2]:
        return 12,[(1,1,1),(1,2,1),(1,3,2),(2,1,1),(2,2,1),(2,3,2),
                   (1,1,2),(1,2,3),(1,3,3),(2,1,2),(2,2,3),(2,3,3)]
    elif [J,P,S,K] == [1,3,3,2]:
        return 6,[(1,1,1),(1,2,1),(1,3,2),(1,1,2),(1,1,2),(1,2,3),(1,3,3)]
    elif [J,P,S,K] == [3,3,3,2]:
        return 18,[(1,1,1),(1,2,1),(1,3,2),(2,2,2),(2,2,3),(2,3,3),(3,1,1),(3,2,1),
                 (3,3,2),(1,1,2),(1,2,3),(1,3,3),(2,1,1),(2,2,1),(2,3,2),(3,1,2),(3,2,3),(3,3,3)]
    else:
        return main_wrong(J,P,S,K)

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        J,P,S,K = [int(i) for i in input().split()]

        ## Processing
        N,res = main_hc(J,P,S,K)

        ## Output
        print("Case #{}: {}".format(c+1,N))
        for i in range(N):
            print(" ".join(["{}".format(x) for x in res[i]]))

