import collections
import heapq
import itertools

T = input()

for t in xrange(T):
    C, D, V = map(int, map(int, raw_input().split()))
    coin = map(int, map(int, raw_input().split()))
    
    possible = [0] * (V + 1)
    possible[0] = 1
    
    for i in xrange(1, D + 1):
        for c in itertools.combinations(coin, i):
            s = sum(c)
            if s <= V:
                possible[s] = 1
    
    result = 0
    for i in xrange(V + 1):
        if possible[i] == 0:
            result += 1
            for j in xrange(V, -1, -1):
                if possible[j] == 1 and j + i <= V:
                    possible[j + i] = 1 
    
    print 'CASE #{}: {}'.format(t + 1, result)
