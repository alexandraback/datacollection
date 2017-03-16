__author__ = 'ar'

cache = [100000000] * (1000010)

def rev(a):
    return int(str(a)[::-1])

def poss(a):
    rev(rev(a)) == a

def precompute():
    cache[1] = 1
    for i in range(2, 1000001):
        r = rev(i)
        cache[i] = cache[i-1] + 1
        if r < i and rev(r) == i:
            cache[i] = min(cache[i], cache[r] + 1)

if __name__ == "__main__":
    t = int(input())
    precompute()
    for idx in range(0, t):
        a = int(input())
        res = cache[a]
        print "Case #%d: %s" % (idx + 1, res)
