import heapq

def solve(panc):
    max_p = max(panc)

    ans = None

    for max_size in reversed(xrange(1, max_p + 1)):
        cur_time = 0
        s = 0
        for p in panc:
            cur_time += (p - 1) / max_size

            c_s = p % max_size
            if p >= max_size:
                c_s = max_size
            if c_s > s:
                s = c_s

        cur_time += s
        if ans is None or cur_time < ans:
            ans = cur_time

    return ans

T = int(raw_input())

for i in xrange(T):
    D = int(raw_input())
    panc = [int(x) for x in raw_input().split()]

    print 'Case #%d: %d' % (i + 1, solve(panc))
