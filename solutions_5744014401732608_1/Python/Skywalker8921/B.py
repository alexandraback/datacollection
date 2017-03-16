import sys,math
from itertools import *

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def N_chemins(G,i,j):
    res = 0 if i < j else 1
    for ii in G[i]:
        #printerr(i,ii,j)
        res += N_chemins(G,ii,j)
    return res

def print_graph(B,G):
    res = ""
    for i in range(B):
        for j in range(B):
            if j in G[i]:
                res += "1"
            else:
                res += "0"
        if i < B-1:
            res += "\n"
    return res

def subset_of_int(B,x):
    s = set()
    for i in range(B):
        if (x % 2):
            s.add(B-i-1)
        x = (x//2)
    return s

def subsets(B,S):
    n = len(S)
    res = [subset_of_int(B,x) for x in range(2**n)]
    return res
            
def main_small(B,M):
    cands = product(*[subsets(B,{j for j in range(i+1,B)}) for i in range(B)])
    for c in cands:
        #printerr(c)
        G = []
        for i in range(B):
            G.append(c[i])
        N = N_chemins(G,0,B-1)
        #printerr(N,G)
        if N == M:
            return True, G
    return False,[]

def int_to_bin (M):
    res = []
    d = 0
    while M:
        if (M%2):
            res.append(d)
        d += 1
        M = M//2
    res.reverse()
    return res

def main_long(B,M):
    G = [set() for i in range(B)]
    if M > 2**(B-2) :
        return False,G
    else:
        b = int_to_bin(M)
        printerr(b)
        d0 = b[0]
        cur = B-d0-2
        #printerr(d0,cur)
        for i in range(cur,B):
            G[i] = set(range(i+1,B))
        if cur > 0:
            cur = cur-1
            G[cur].add(cur+1)
            for dd in b[1:]:
                G[cur].add(B-dd)
            if cur > 0:
                G[0].add(cur)
        #printerr (N_chemins(G,0,B-1),M)
        return True, G
    

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        B,M = [int(i) for i in input().split()]

        ## Processing
        test,G = main_long(B,M)

        ## Output
        print("Case #{}: {}".format(c+1,"POSSIBLE" if test else "IMPOSSIBLE"))
        if test:
            print(print_graph(B,G))


