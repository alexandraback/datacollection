import sys,math

from collections import *

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

# def main(L):
#     C = 0
#     S1 = [t[0] for t in L]
#     S2 = [t[1] for t in L]
#     for t in L:
#         w1, w2 = t
#         if S1.count(w1) > 1 and S2.count(w2) > 1 :
#             C += 1
#     return C

def main(L):
    C = 0
    s1 = set({})
    s2 = set({})
    m1 = set({})
    m2 = set({})
    m12 = {}
    m21 = {}
    for t in L:
        w1, w2 = t
        if w1 in s1 and w2 in s2:
            C += 1
        else:
            if w1 in m1:
                C += 1
                m1.remove(w1)
            if w2 in m2:
                C += 1
                m2.remove(w2)
            if w1 in m12:
                for ww2 in m12[w1]:
                    m2.add(ww2)
                m12[w1] = {}
            if w2 in m21:
                for ww1 in m21[w2]:
                    m1.add(ww1)
                m21[w2] = {}
            if w1 in s1:
                m2.add(w2)
            elif w2 in s2:
                m1.add(w1)
            else:
                if w1 not in m12:
                    m12[w1] = set({})
                m12[w1].add(w2)
                if w2 not in m21:
                    m21[w2] = set({})
                m21[w2].add(w1)
            s1.add(w1)
            s2.add(w2)
    return C
        

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        n = int(input())
        L = []
        for i in range(n):
            W = input().split()
            L.append(W)
        
        ## Processing
        res = main(L)

        ## Output
        print("Case #{}: {}".format(c+1,res))


