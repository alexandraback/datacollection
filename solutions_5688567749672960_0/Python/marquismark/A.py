#!/usr/bin/env python

TEST="""4
1
19
23
10000"""
#raw_input = iter(TEST.splitlines()).next


def num(units):
    return int("".join([str(s) for s in units]))

def rev_num(N):
    units = []
    nn = N
    while nn:
        nn, m = divmod(nn,10)
        units = [m] + units

    r = 0
    u = 1
    for d in units:
        r+=d*u
        u*=10
    return r


def solve(N):
    p = N
    r = 0
    while p >= 10:

        units = []
        nn = p
        while nn:
            nn, m = divmod(nn,10)
            units = [m] + units

        frag = num(units[-len(units)/2:])

        if frag == 0:
            r += 1
            p = p-1
            continue

        elif frag > 1:
            # Best to walk back to a 1?
            r += (frag-1)
            p = p-(frag-1)
       
        elif frag == 1:
            # might be worth switching?
            revP = rev_num(p)
            if revP < p:
                r += 1
                p = revP
            else:
                # Otherwise subtract by default?
                r += 1
                p = (p-1)

    return r+p



T = int(raw_input())
for case in range(1,T+1):
    N = int(raw_input())
    print("Case #%s: %s" % (case, solve(N)))
