#! /usr/bin/env python

from sets import Set


t = int(input())
for i in range(1, t + 1):
    N = int(raw_input())
    set = Set([])
    for j in range(2*N - 1):
        for n in str(raw_input()).split(" "):
            n_int = int(n)
            if n_int in set:
                set.remove(n_int)
            else:
                set.add(n_int)
    output = list(set)
    output.sort()
    print("Case #{}: {}".format(i, ' '.join(str(x) for x in output)))
