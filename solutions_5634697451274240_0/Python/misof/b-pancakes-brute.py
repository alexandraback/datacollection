from collections import defaultdict
from queue import Queue

def flip(S): return ''.join('+' if x=='-' else '-' for x in S[::-1] )

T = int(input())
for tid in range(1,T+1):
    start = input()
    dist = defaultdict(lambda:10**18)
    dist[start] = 0
    Q = Queue()
    Q.put(start)
    while not Q.empty():
        curr = Q.get()
        for f in range(1,len(curr)+1):
            nxt = flip( curr[:f] ) + curr[f:]
            if dist[nxt] <= dist[curr] + 1: continue
            dist[nxt] = dist[curr] + 1
            Q.put(nxt)
    print('Case #{}: {}'.format(tid,dist['+'*len(start)]))
