#!/usr/bin/env python3

from collections import deque

def compute_fakes():
    n = int(input())
    strs = [input().split() for _ in range(n)]
    nbrs = dict()
    def add_nbr(a, b, v):
        if a in nbrs:
            nbrs[a][b] = v
        else:
            nbrs[a] = {b: v}

    for a, b in strs:
        add_nbr((False, a), (True, b), False)
        add_nbr((True, b), (False, a), False)

    matched = dict()
    op = set((False, x) for x, y in strs)
    while op:
        prev = dict()
        def add_path(v):
            on = True
            while v in prev:
                p = prev[v]
                matched[v] = p
                matched[p] = v

                nbrs[v][p] = on
                nbrs[p][v] = on

                on = not on
                v = p
            op.remove(v)

        found = False
        d = deque(op)
        while d and not found:
            cur = d.popleft()
            if cur[0]:
                m = matched[cur]
                prev[m] = cur
                d.append(m)
            else:
                for adj, val in nbrs[cur].items():
                    if val: continue # Skip matched pair
                    if adj in prev: continue # Already visited
                    prev[adj] = cur
                    if adj not in matched:
                        add_path(adj)
                        found = True
                        break
                    else:
                        d.append(adj)

        if not found:
            break

    real = len(nbrs) - len(matched) // 2

    return n - real

def run_test(i):
    print('Case #%d: %s' % (i, compute_fakes()))

def main():
    T = int(input())

    for t in range(T):
        run_test(t+1)

def extensive():
    import random
    for i in range(100000):
        compute_insomnia(random.randint(0, 10**6))
    exit(0)

if __name__ == '__main__': main()