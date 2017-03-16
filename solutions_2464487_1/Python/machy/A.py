import sys

def get_line():
    return sys.stdin.readline().strip()

def read_nums():
    return [int(item) for item in get_line().split(" ")]

def satisfy(r, t, cnt):
    amount = 0
    amount += (r+cnt*2 + r)*cnt - cnt
    return amount <= t

def solve(r, t):
    left = 0
    right = 10**19
    while left+1 < right:
        middle = (left+right) / 2
        if satisfy(r, t, middle):
            left = middle
        else:
            right = middle
    return left


(T,) = read_nums()
for te in xrange(1, T+1):
    (r, t) = read_nums()
    print "Case #%d: %d" % (te, solve(r, t))

