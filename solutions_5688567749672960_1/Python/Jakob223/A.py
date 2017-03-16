from collections import defaultdict
from heapq import *

def edges(v1):
    flip = int(str(v1)[-1::-1])
    return (v1+1,flip) if flip>v1 else (v1+1,)
 
def dijkstra(f, t): 
    q, seen = [(0,f)], set()
    while q:
        (cost,v1) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            # path = (v1,)+ path
            if v1 == t: return cost#,path
 
            for v2 in edges(v1):
                if v2 not in seen:
                    heappush(q, (cost+1, v2))
 
    return float("inf")
 

def cost10(n,pownum):
    if n==10:
        return 9
    elif pownum%2==0:
        return 2*(10**(pownum/2))-1
    else:
        return 11*(10**(pownum/2))-1
def addleftright(N):
    Ns = str(N)
    left = Ns[:len(Ns)/2]
    right = Ns[len(Ns)/2:]
    if left=='':
        return int(right)-1
    if int(left[-1::-1])==1:
        return int(right)
    return int(left[-1::-1])+int(right)
def ans(N):
    current = 1
    spent = 1
    pownum = 0
    while current*10 <= N:
        spent += cost10(current*10,pownum+1)
        current *= 10
        pownum += 1
    # print current,N,dijkstra(current,N)
    if current != N and N%10==0:
        spent += 1
        N -= 1
    # if addleftright(N)!=dijkstra(current,N):
    #     print "ERROR ",N,addleftright(N),dijkstra(current,N)
    return spent+addleftright(N)
for i,Ns in enumerate(open('A-large.in').read().split('\n')[:-1]):
 if i:
    N = int(Ns)
    print "Case #%d: %d" % (i,ans(N))