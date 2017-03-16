import math

N = 32
J = 500

def eval_number(n, b):
    v = 0
    for i in xrange(N):
        v = v * b
        if (n[i] == 1):
            v += 1
    return v

def can_be_divided(v):
    for i in xrange(2, min(1000, int(math.sqrt(v)) + 1)):
        if v % i == 0:
            return i
    return None

def check_number(n):
    ds = [0] * 9
    for i in xrange(9):
        b = 2 + i
        v = eval_number(n, b)
        # print v
        d = can_be_divided(v)
        if d is None:
            return None
        ds[i] = d
    return ds

def next_number(n):
    i = N - 2
    while n[i] == 1:
        n[i] = 0
        i -= 1
    n[i] = 1

curr_number = [1] + ((N - 2) * [0]) + [1]

found = 0
print "Case #1:"
while found < J:
    is_jamcoin = check_number(curr_number)
    if is_jamcoin is not None:
        # print "YES", curr_number, is_jamcoin
        print "".join([str(x) for x in curr_number]),
        print " ".join([str(x) for x in is_jamcoin])
        found += 1
    next_number(curr_number)
