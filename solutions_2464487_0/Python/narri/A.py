import sys

def series_sum(R, k):
    #2*R + 1, keep adding 4
    #k * (2*R + 1) - 2*(k*(k-1))
    return k * (2*R + 1) + 2*(k*(k-1))

def solve(r, t):
    if series_sum(r, 1) > t:
        return 0
    low = 1
    while series_sum(r, low*2) <= t:
        low *= 2
    high = low*2
    mid = low
    while high - low > 2:
        mid = low + (high-low)//2
        if series_sum(r, mid) <= t:
            low = mid
        else:
            high = mid
    while series_sum(r, low+1) <= t:
        low += 1
    return low

ZZ = [int(t) for t in """1 9 1 10 3 40 1 1000000000000000000 10000000000000000 1000000000000000000""".split()]

def main():
    T = int(sys.stdin.readline())
    for cn in range(1, T+1):
        x,y = [int(s) for s in sys.stdin.readline().strip().split()]
        print "Case #%d: %s" % (cn, solve(x,y))

if __name__ == '__main__':
    main()
        
