import sys
from collections import defaultdict

T = int(sys.stdin.readline())
case = 1
for case in range(1, T+1):
    N = int(sys.stdin.readline().strip())
    L = defaultdict(int)
    R = defaultdict(int)
    E = set([])
    for i in range(N):
        A,B = sys.stdin.readline().strip().split()
        L[A]+=1
        R[B]+=1
        E.add((A,B))
    removed = True
    fakers = 0
    while removed:
        removed = False
        for e in E:
            if L[e[0]]>1 and R[e[1]]>1:
                E.remove(e)
                fakers +=1
                L[e[0]] -= 1
                R[e[1]] -= 1
                removed = True
                break
    print "Case #{0}:".format(case), fakers
    #case += 1
        
