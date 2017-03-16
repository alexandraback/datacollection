#!/usr/bin/python

import sys
import logging
import itertools

logging.basicConfig(stream=sys.stderr, level=logging.DEBUG)

def solve(nj, np, ns, k):
    jp_combs = {}
    js_combs = {}
    ps_combs = {}
    for j in range(1, nj+1):
        for p in range(1, np+1):
            jp_combs[(j,p)] = 0
        for s in range(1, ns+1):
            js_combs[(j,s)] = 0
    for p in range(1, np+1):
        for s in range(1, ns+1):
            ps_combs[(p,s)] = 0
    res = []
    not_res = []
    for j, p in itertools.product(range(1, nj+1), range(1, np+1)):
        s_list = range(1, ns+1)
        while s_list:
            min_js = float('inf')
            min_ps = float('inf')
            best_s_js = -1
            best_s_ps = -1
            for s in s_list:
                js = js_combs[(j, s)]
                ps = ps_combs[(p, s)]
                if js < min_js:
                    min_js = js
                    best_s_js = s
                if ps < min_ps:
                    min_ps = ps
                    best_s_ps = s

            if min_js < min_ps:
                s = best_s_js
            else:
                s = best_s_ps
            s_list.remove(s)

            logging.debug('trying %d %d %d', j, p, s)
            if jp_combs[(j, p)] == k:
                logging.debug('broke j p count')
                not_res.append([j, p, s])
                continue
            if js_combs[(j, s)] == k:
                logging.debug('broke j s count')
                not_res.append([j, p, s])
                continue
            if ps_combs[(p, s)] == k:
                logging.debug('broke p s count')
                not_res.append([j, p, s])
                continue

            jp_combs[(j, p)] += 1
            js_combs[(j, s)] += 1
            ps_combs[(p, s)] += 1

            res.append([j, p, s])

    for j, p, s in res:
        if jp_combs[(j,p)] == k and js_combs[(j,s)] == k and ps_combs[(p,s)] == k:
            for jj, pp, ss in not_res:
                if jp_combs[jj,pp] < k-1 and js_combs[jj, ss] < k-1 and ps_combs[pp,ss] < k-1:
                    res.remove([j, p, s])
                    res.append([jj, pp, ss])
                    not_res.remove([jj, pp, ss])

        

    return res

first = True
n = 0
for line in sys.stdin:
    if first:
        first = False
    else:
        n = n + 1
        j, p, s, k = map(int, line.split(' '))
        combs = solve(j, p, s, k)
        print "Case #%d: %d" % (n, len(combs))
        for r in combs:
            print ' '.join(map(str, r))
