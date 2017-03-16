#!/usr/bin/env python3

from heapq import *

def solve(fin, fout):
    n = int(fin.readline())
    
    wall = [0] * 900
    new_wall = [0] * 900
    tribes = []
    cal = [None] * 676061
    s = 0
    heap = []
    for i in range(n):
        data = list(map(int, fin.readline().split()))
        tribes.append(data)
        di = data[0]
        if cal[di] is None:
            cal[di] = set()
        cal[di].add(i)
        heappush(heap, di)

    while len(heap) > 0:
        d = heap[0]
        while len(heap) > 0 and heap[0] == d:
            heappop(heap)

        c = cal[d]
        for i in c:
            di, ni, wi, ei, si, ddi, dpi, dsi = tribes[i]
            success = False
            for l in range(wi * 2, ei * 2 + 1):
                if wall[l - 450] < si:
                    if not success:
                        s += 1
                        print("HIT: [{0}, {1}] @ {2}".format(wi, ei, si))
                        success = True
                    new_wall[l - 450] = max(new_wall[l - 450], si)
            
            ni -= 1
            if ni == 0: continue
            wi += dpi
            ei += dpi
            si += dsi
            di += ddi

            tribes[i] = [di, ni, wi, ei, si, ddi, dpi, dsi]
            if cal[di] is None:
                cal[di] = set()
            cal[di].add(i)
            heappush(heap, di)

        for i in range(len(wall)):
            wall[i] = max(wall[i], new_wall[i])

    fout.write(str(s) + '\n')
