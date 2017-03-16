from heapq import *


def solve(Ps):
    #print Ps
    queue0 = []
    for p in Ps:
        heappush(queue0, -p)

    for best_time in xrange(1 + max(Ps)):
        for eat_from in xrange(1, 1 + best_time):
            queue = queue0[:]
            for t in xrange(best_time - eat_from):
                largest = -heappop(queue)
                if largest <= eat_from:
                    return best_time
                heappush(queue, -(largest - eat_from))
            largest = -heappop(queue)
            if largest <= eat_from:
                return best_time
            #print best_time, time_left, [-x for x in queue]


if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        D = int(raw_input())
        Ps = map(int, raw_input().split())
        print "Case #{0}:".format(t + 1), solve(Ps)
