#!/bin/python
def read(mode=2):
    inp = input().strip()
    if mode == 0: return inp
    if mode == 1: return inp.split()
    if mode == 2: return list(map(int,inp.split()))
T = int(read(0))
for i in range(T):
    N = int(read(0))
    d = [read() for j in range(2*N-1)]
    flat = []
    que = []
    for j in d:
        flat.extend(j)
    for j in flat:
        if j not in que:
            que.append(j)
        else:
            que.remove(j)
    que.sort()
    print('Case #{}: {}'.format(i+1, ' '.join(map(str,que))))
