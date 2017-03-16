#!/usr/bin/env python
import heapq
import sys
from collections import defaultdict

def possible_dests(point, N, M):
    x, y = point
    directions = ((0, 1), (1, 0), (-1, 0), (0, -1))
    results = []
    for xd, yd in directions:
        if 0 <= x+xd < N and 0 <= y+yd < M:
            results.append((x+xd, y+yd))
    return results

def howlong(start, end, time, H, floors, ceilings):
    sx, sy = start
    ex, ey = end
    if (floors[sx][sy] > ceilings[ex][ey] - 50 or 
        floors[ex][ey] > ceilings[ex][ey] - 50 or
        floors[ex][ey] > ceilings[sx][sy] - 50):
        return None

    water_level = max(0, H-time*10)
    extra_water = max(0, water_level - (ceilings[ex][ey]-50))
    if water_level == H and extra_water == 0:
        return 0
    time_to_wait = extra_water/10.0
    water_level-=extra_water
    if water_level < floors[sx][sy]+20:
        travel_time = 10
    else:
        travel_time = 1
    return time_to_wait+travel_time

def main(args):
    finname = '%s.in' % args[1]
    foutname = '%s.out' % args[1]
    with open(finname, 'r') as fin, open(foutname, 'w') as fout:
        T = int(fin.readline().strip())
        for casenum in xrange(1, T+1):
            H, N, M = [int(n) for n in fin.readline().strip().split()]
            ceilings = []
            for _ in xrange(N):
                ceilrow = [int(ceil) for ceil in fin.readline().strip().split()]
                ceilings.append(ceilrow)
            floors = []
            for _ in xrange(N):
                floorrow = [int(fl) for fl in fin.readline().strip().split()]
                floors.append(floorrow)

            pending = []
            heapq.heappush(pending,
                           (0,
                            (None, (0, 0))
                            ))
            best_times = [[sys.maxint for _j in xrange(M)] for _i in xrange(N)]
            best_times[0][0] = 0

            while pending:
                time, edge = heapq.heappop(pending)
                start, end = edge
                dests = possible_dests(end, N, M)
                for dest in dests:
                    td = howlong(end, dest, time, H, floors, ceilings)
                    if td is None: continue
                    destx, desty = dest
                    newtime = time + td
                    if best_times[destx][desty] > newtime:
                        best_times[destx][desty] = newtime
                        heapq.heappush(pending, (newtime, (end, dest)))
            fout.write('Case #%s: %s\n' % (casenum, best_times[N-1][M-1]))
                
if __name__ == '__main__':
    status = main(sys.argv)
    sys.exit(status)
