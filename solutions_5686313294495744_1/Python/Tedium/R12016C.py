from string import *
from random import *
from time import *

def random_search (pairs, F, S, max_time):
    start = time()
    out = 0
    while time() - start < max_time:
        f = [0] * F
        s = [0] * S
        for (a, b) in pairs:
            f[a] += 1
            s[b] += 1

        v = 0
        shuffle(pairs)
        for (a, b) in pairs:
            if f[a] > 1 and s[b] > 1:
                v += 1
                f[a] -= 1
                s[b] -= 1
        out = max(out, v)
    return out
        

time_allowed = 7 * 60

f = open('C-large.in', 'r')
outf = open('C-large.out','w')
inp = f.read().split("\n")
f.close()

T = int(inp[0])

inpind = 1
for itr in range(1, T+1):
    N = int(inp[inpind])
    names = inp[inpind+1:inpind+1+N]
    inpind += N+1

    firsts = {}
    seconds = {}
    pairs = []
    for i in range(N):
        (first, second) = tuple(names[i].split())
        if not first in firsts:
            firsts[first] = len(firsts)
        if not second in seconds:
            seconds[second] = len(seconds)
        pairs.append((firsts[first], seconds[second]))

    out = random_search(pairs, len(firsts), len(seconds), time_allowed/T)
    
    outf.write("Case #%d: %d\n" % (itr, out))
outf.close()
