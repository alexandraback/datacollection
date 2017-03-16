import os, sys, math

infile = sys.stdin
pi = math.pi

def cost(k, r):
    return float(k * (2 * r + 2 * k - 1))

def get_bound(r, t):
    low = 1
    while cost(low, r) <= float(t):
        low *= 2
    return low / 2, low
    

def solve(r, t):
    low, high = get_bound(r, t)
    while low < high - 1:
        mid = low + (high - low) / 2
        if cost(mid, r) <= t:
            low = mid
        else:
            high = mid
    return low

if __name__ == "__main__":
    num = int(infile.readline())
    for i in xrange(num):
        r, t = [int(item) for item in infile.readline().split()]
        ret = solve(r, t)
        print "Case #%d: %d" % (i+1, ret)
