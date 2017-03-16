#!/usr/bin/env python

import sys
from collections import defaultdict

def main():
    inp = iter(sys.stdin)
    num_cases = int(inp.next())
    for case in range(1, num_cases + 1):
        attacks = defaultdict(list)
        wall = defaultdict(lambda: 0)
        num_tribes = int(inp.next())
        breaches = 0
        for tribe in range(num_tribes):
            d_0, n_a, w_0, e_0, s_0, d_d, d_p, d_s = map(int, inp.next().split())
            for attack in range(n_a):
                d = d_0 + d_d * attack
                w = w_0 + d_p * attack
                e = e_0 + d_p * attack
                s = s_0 + d_s * attack
                attacks[d].append((tribe, w, e, s))
                #print tribe, d, w, e, s
        for attack_day in sorted(attacks.keys()):
            wall_update = defaultdict(lambda: 0)
            for attack in attacks[attack_day]:
                tribe, w, e, s = attack
                for wallpiece in range(w, e):
                    if wall[wallpiece] < s:
                #        print "breach @[%d, %d] by tribe %d, d: %d, s: %d" %(w, e, tribe+1, attack_day, s)
                        breaches += 1
                        for wp in range(w, e):
                            wall_update[wp] = max(wall_update[wp], s)
                        break
                #else:
                #    print "no breach @[%d, %d] by tribe %d, d: %d, s: %d" % (w, e, tribe+1, attack_day, s)
                
            for wp, nh in wall_update.iteritems():
                wall[wp] = max(wall[wp], nh)
            #print dict(wall)
        print "Case #%d: %d" % (case, breaches)
if __name__ == '__main__':
    main()
