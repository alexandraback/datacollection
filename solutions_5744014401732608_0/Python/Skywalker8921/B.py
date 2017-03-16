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
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        B,M = [int(i) for i in input().split()]

        ## Processing
        test,G = main_small(B,M)

        ## Output
        print("Case #{}: {}".format(c+1,"POSSIBLE" if test else "IMPOSSIBLE"))
        if test:
            print(print_graph(B,G))


