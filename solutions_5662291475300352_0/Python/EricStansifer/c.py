from common import *

import heapq

def main(casenum):
    x = []
    y = []

    n = readint()
    ds = []
    hs = []
    ms = []
    for i in range(n):
        d, h, m = readints()
        ds.append(d)
        hs.append(h)
        ms.append(m)
        for j in range(h):
            m_ = m + j
            heapq.heappush(x, ((360 - d) * m_, 360 * m_))

    num = len(x)

    best = num
    cur = num

    while cur - len(x) < best:
        if len(y) == 0 or x[0][0] < y[0][0]:
            a, b = heapq.heappop(x)
            cur -= 1
            if cur < best:
                best = cur
        else:
            a, b = heapq.heappop(y)
            cur += 1

        heapq.heappush(y, (a + b, b))

    writecase(casenum, best)

run(main)
