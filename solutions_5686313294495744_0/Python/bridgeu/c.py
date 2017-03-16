import sys
from collections import Counter
import random
import copy

def read_ints(inp):
    return [int(x) for x in inp.readline().split()]

def handle(inp, i):
    T = int(inp.readline())

    phrases = [inp.readline().strip().split() for _ in range(T)]

    w0s = Counter([phrase[0] for phrase in phrases])
    w1s = Counter([phrase[1] for phrase in phrases])

    minimal_set = []

    for w0, w1 in phrases:
        if w0s[w0] == 1 or w1s[w1] == 1:
            minimal_set.append([w0, w1])
            w0s.pop(w0, None)
            w1s.pop(w1, None)

    best_found = 10000000
    for _ in range(40):
        # Now add any with both still in demand
        this_time = len(minimal_set)
        random.shuffle(phrases)
        w0s_loc = copy.copy(w0s)
        w1s_loc = copy.copy(w1s)

        for w0, w1 in phrases:
            if w0s_loc[w0] > 0 and w1s_loc[w1] > 0:
                this_time += 1
                w0s_loc.pop(w0, None)
                w1s_loc.pop(w1, None)

        # Now we need a further len(w1s) + len(w0s)
        this_time += len(w0s_loc) + len(w1s_loc)
        if best_found > this_time:
            best_found = this_time
    return str(T - best_found)

f_in = sys.stdin
N = int(f_in.readline())
f_out = sys.stdout

for i in range(N):
    f_out.write("Case #%i: " % (i+1))
    result = handle(f_in, i)
    f_out.write(result)
    f_out.write("\n")
