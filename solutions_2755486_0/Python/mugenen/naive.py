import sys
import collections

T = int(raw_input())
for i in xrange(1, T + 1):
    N = int(raw_input())
    attack = []
    for j in xrange(N):
        d, n, w, e, s, delta_d, delta_p, delta_s = map(int, raw_input().split())
        for k in xrange(n):
            attack.append((d + k * delta_d, (w + k * delta_p) * 2, (e + k * delta_p) * 2, s + k * delta_s))
    attack.sort()
    count = 0
    before = -1
    area = collections.Counter()
    
    todo = []
#    for a in attack:
#        print a
    for d, w, e, s in attack:
        if before != d:
            for t_w, t_e, t_s in todo:
                for j in xrange(t_w, t_e + 1):
                    area[j] = max(t_s, area[j])
            todo = []
        for j in xrange(w, e + 1):
            if area[j] < s:
                count += 1
                todo.append((w, e, s))
                before = d
#                print d, w/2, e/2, s
                break
    print "Case #{0}: {1}".format(i, count)
    print i
