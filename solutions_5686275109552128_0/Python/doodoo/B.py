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


    # h = []
    # for p in panc:
    #     heapq.heappush(h, -p)

    # total = 0
    # while True:
    #     l_p = -heapq.heappop(h)
    #     n = 1

    #     if l_p == -1:
    #         break

    #     if len(h) > 0:
    #         q = heapq.heappop(h)
    #         while q == -l_p:
    #             n += 1
    #             if len(h) == 0:
    #                 break
    #             q = heapq.heappop(h)

    #         if q != -l_p:
    #             heapq.heappush(h, q)

    #     # Test whether it worth splitting the largest
    #     # dinners
    #     left = (l_p  + 1) / 2
    #     if left + n > l_p:
    #         # don't break
    #         for i in xrange(n):
    #             heapq.heappush(h, -l_p)
    #         break

    #     # break
    #     total += n
    #     for i in xrange(n):
    #         heapq.heappush(h, -left)
    #         heapq.heappush(h, -(l_p - left))

    # return total - heapq.heappop(h)

T = int(raw_input())

for i in xrange(T):
    D = int(raw_input())
    panc = [int(x) for x in raw_input().split()]

    print 'Case #%d: %d' % (i + 1, solve(panc))
