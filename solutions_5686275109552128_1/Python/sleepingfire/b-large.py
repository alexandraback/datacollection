import sys
from heapq import heappush, heappop

def try_max_unit(cakes, m):
    num = 0
    for i in range(len(cakes)):
        cake = cakes[i]
        if cake <= m:
            continue
        parts = cake / m
        if cake % m > 0:
            parts += 1
        num += parts - 1
    return num + m

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    N = int(in_file.readline())
    for case_num in range(N):
        D = int(in_file.readline())
        cakes = [int(z) for z in in_file.readline().split()]
        max_cakes = max(cakes)
        m = max_cakes
        for i in range(1, max_cakes):
            m = min(m, try_max_unit(cakes, i))

        print "Case #{}: {}".format(case_num+1, m)

    in_file.close()
