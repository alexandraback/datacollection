#!/usr/bin/python

def solve(ns, ks):
    l = [x[1] for x in sorted([(n, 'N') for n in ns] + [(k, 'K') for k in ks])]

    # deceitful war
    l2 = l[:]
    d_score = 0
    while l2:
        if l2.pop(0) == 'N':
            l2.reverse()
            l2.remove('K')
            l2.reverse()
        else:
            l2.remove('N')
            d_score += 1

    # war
    w_score = 0
    count = 0
    for c in l[::-1]:
        if c == 'N':
            if count:
                count -= 1
            else:
                w_score += 1
        else:
            count += 1

    return '%i %i' % (d_score, w_score)



T = int(raw_input())
for i in range(T):
    raw_input()
    ns = map(float, raw_input().split())
    ks = map(float, raw_input().split())
    print "Case #%i: %s" % (i+1, solve(ns, ks))
