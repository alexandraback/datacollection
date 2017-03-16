import sys
import heapq


def solve(pairs):
    pairs.sort(reverse=True)
    left = []
    #print pairs
    k = 0
    stars = 0
    while pairs:
        while left:
            if left[0] > stars:
                break
            stars += 1
            k += 1
            heapq.heappop(left)

        if pairs[-1][0] <= stars:
            stars += 2
            k += 1
            pairs.pop()
            continue

        for i, p in enumerate(pairs):
            if p[1] <= stars:
                break
        else:
            return None
        stars += 1
        k += 1
        heapq.heappush(left, pairs.pop(i)[0])

    while left:
        if left[0] > stars:
            break
        stars += 1
        k += 1
        heapq.heappop(left)
    if left:
        return None
    return k

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in range(1, T+1):
        N = int(f.readline())
        pairs = [map(int, f.readline().split())[::-1] for i in xrange(N)]

        res = solve(pairs)
        if res is None:
            print "Case #{0}: Too Bad".format(t)
        else:
            print "Case #{0}: {1}".format(t, res)

if __name__ == "__main__":
    main()