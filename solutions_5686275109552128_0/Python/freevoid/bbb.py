import sys
import heapq
from collections import defaultdict

def solve(d, pancakes):
    pancakes_counts = defaultdict(int)

    heap = []

    for p in pancakes:
        pancakes_counts[p] += 1

    for p in pancakes_counts.iterkeys():
        heapq.heappush(heap, -p)

    specials = 0

    cur_min = -heap[0]

    while True:
        p = -heapq.heappop(heap)
        cur_min = min(cur_min, p + specials)

        #print 'p =', p
        if p == 1:
            return cur_min

        while heap and heap[0] == -p:
            heapq.heappop(heap)

        c = pancakes_counts[p]
        #print 'c =', c
        #print 'current specials:', specials

        halfp = p // 2
        halfp_upper = halfp + p % 2

        if p < (c + halfp_upper):
            #print 'Moving not worth it'
            return cur_min
        else:
            specials += c
            if halfp not in pancakes_counts:
                heapq.heappush(heap, -halfp)

            if p % 2 == 1:
                if halfp + 1 not in pancakes_counts:
                    heapq.heappush(heap, -(halfp + 1))

                pancakes_counts[halfp] += c
                pancakes_counts[halfp_upper] += c
            else:
                pancakes_counts[halfp] += 2*c


def read_ints():
    return map(int, sys.stdin.readline().split(' '))

t, = read_ints()
for i in range(t):
    d, = read_ints()
    pancakes = read_ints()
    print 'Case #%d: %d' % (i + 1, solve(d, pancakes))
