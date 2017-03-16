from toolz import *
from itertools import *

def read_int():
    return int(raw_input())

def read_ints():
    return map(int, raw_input().split())

for case in range(read_int()):
    N = read_int()
    inp = [False] * 2501
    for i in range(N + N - 1):
        for j in read_ints():
            inp[j] = not inp[j]
    ans = [i for (i, b) in enumerate(inp) if b]
    ans = ' '.join(map(str, ans))
    print "Case #%d: %s" % (case+1, ans)
