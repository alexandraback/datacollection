from sys import stdout
from multiprocessing import Pool

import gmpy2
from heapq import heappush, heappop
from random import randint


def decode(S):
    l = 0
    start = 0
    for s in reversed(S):
        if s not in ['+', '-']:
            continue
        l += 1
        start *= 2
        if s == '+':
            start += 1
    return l, start

def show(k, l):
    return bin(k)[2:].zfill(l)

def solve(start, l):
    def flip(k, c):
        if c >= l:
            raise RuntimeError('c should < l')
        mod = 2 ** (c+1)
        ret = k // mod * mod
        for i in range(c+1):
            if (k & (1 << (c-i))) == 0:
                ret |= 1 << i
        return ret

    def star(k):
        left = l
        ret = 0
        now = 1
        while k != 0:
            if k % 2 != now:
                now = k%2
                ret += 1
            left -= 1
            k //= 2
        if left > 0 and now != 0:
            ret += 1
        return ret

    steps = {}
    heap = []
    steps[start] = 0
    heappush(heap, (star(start), start))
    goal = (2 ** l)-1
    if start == goal:
        return 0
    while True:
        assert(len(heap) > 0)
        _, now = heappop(heap)
        step = steps[now]+1
        for c in range(l):
            new = flip(now, c)
            if new == goal:
                return step
            if new not in steps:
                steps[new] = step
                heappush(heap, (star(new)+step, new))

if __name__ == '__main__':
    namein = 'B-large.in'
    nameout = 'B-large.out'

    fin = open(namein, 'r')
    fout = open(nameout, 'w')
    # fout = stdout
    T = int(fin.readline())
    pool = Pool()
    res = []
    for i in range(1, T+1):
        l, start = decode(fin.readline())
        # l = 100
        # start = randint(0, 2**l-1)
        res.append(pool.apply_async(solve, (start, l)))
    for i in range(1, T+1):
        print('{} done'.format(i))
        print('Case #{}: {}'.format(i, res[i-1].get()), file=fout)

# for _ in range(100):
#     l = 100
#     print(solve(randint(0, 2**l-1), l))

