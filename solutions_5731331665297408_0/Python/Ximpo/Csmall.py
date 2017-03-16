#!/usr/bin/env python3
import sys
from itertools import permutations
from multiprocessing import Pool, cpu_count

def solve(n):
    N, M, cities, adj = n

    best = None
    for p in permutations(list(range(1, N+1))):
        p = list(p)
        #print(p, end=' ')
        stack = [p[0]]
        try:
            for i, n in enumerate(p):
                if i == 0:
                    continue
                while n not in adj[stack[-1]]:
                    stack.pop()
                stack.append(n)
            zips = [cities[int(i)-1] for i in p]
            seq = str.join('', zips)
            #print(seq)
            if best is None:
                best = seq
            else:
                best = min(best, seq)
        except:
            #print('bad')
            pass

    return best

if __name__ == '__main__':
    T = int(input())
    testcases = []
    for t in range(T):
        N, M = map(int, input().split())
        cities = []
        for _ in range(N):
            cities.append(input().strip())
        adj = {i:set() for i in range(1, N+1)}
        for _ in range(M):
            a, b = map(int, input().split())
            adj[a].add(b)
            adj[b].add(a)
        testcases.append([N, M, cities, adj])
    pool = Pool(processes=4)
    result = pool.map(solve, testcases)

    for t, r in enumerate(result):
        print('Case #{}: {}'.format(t+1, r))
