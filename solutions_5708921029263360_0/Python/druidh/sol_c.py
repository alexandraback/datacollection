#!/usr/bin/python2.7

for case in range(input()):
    J, P, S, K = map(int, raw_input().split())

    sol = 0
    combs = []
    jp = {}
    js = {}
    ps = {}
    for i in xrange(1, J+1):
        pants = list(range(1, P+1))
#        pants = pants[i-1:] + pants[:i-1]
        for j in pants:
            shirts = list(range(i, S+1))
            shirts.extend(list(range(1, i)))
#            print shirts
#            if (J == 3):
#                shirts = shirts[i-1:] + shirts[:i-1]
#            else:
            shirts = shirts[j-1:] + shirts[:j-1]
#            print J, P, S, j, shirts
            for k in shirts:
                jp_1 = i*10 + j
                js_1 = i*10 + k
                ps_1 = j*10 + k
                cancel = False
                if (jp_1 in jp) and (jp[jp_1] == K):
                    cancel = True
                if (js_1 in js) and (js[js_1] == K):
                    cancel = True
                if (ps_1 in ps) and (ps[ps_1] == K):
                    cancel = True
                if (not cancel):
                    if (jp_1 not in jp):
                        jp[jp_1] = 1
                    else:
                        jp[jp_1] += 1
                    if (js_1 not in js):
                        js[js_1] = 1
                    else:
                        js[js_1] += 1
                    if (ps_1 not in ps):
                        ps[ps_1] = 1
                    else:
                        ps[ps_1] += 1
                    combs.append([i, j, k])

    sol = (J*P*S)
    if (K < S):
        sol = sol - ((S-K)*(J*P))
#    if (len(combs) != sol):
#        print J, P, S, K
    print 'Case #%s: %s' % ((case + 1), len(combs))
    for c in combs:
        print ' '.join(map(str, c))
