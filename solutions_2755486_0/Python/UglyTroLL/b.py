'''
Created on May 12, 2013

@author: uglytroll
'''

def attack_succ(days_dict, statics):
    succ_count = 0
    great_wall = {}
    days = list(days_dict.iterkeys())
    sorted(days)
    for day in days:
        attacks = days_dict[day]
        repair = {}
        for (tribe, attack_n) in attacks:
            stat = statics[tribe]
            (west, east) = (stat[2] + attack_n * stat[6], stat[3] + attack_n * stat[6])
            strength = stat[4] + attack_n * stat[7]
            succ = False
            for position in xrange(west, east):
                if position not in repair and strength >= 0:
                    repair[position] = strength
                else:
                    if strength > repair[position]:
                        repair[position] = strength
                if strength > 0 and (position not in great_wall or great_wall[position] < strength):
                    succ = True
            if succ:
                succ_count += 1
                
        for need in repair:
            if need not in great_wall and repair[need] >= 0:
                great_wall[need] = repair[need]
            else:
                if great_wall[need] < repair[need] and repair[need] >= 0:
                    great_wall[need] = repair[need]
    return succ_count

f = open('/home/uglytroll/codejam/2013/1c/b.in', 'r')
o = open('/home/uglytroll/codejam/2013/1c/b.out', 'w')

T = int(f.readline().strip())
for t in xrange(T):
    tribes = int(f.readline().strip())
    statics = {}
    days = {}
    for tribe in xrange(tribes):
        d, n, w, e, s, delta_d, delta_p, delta_s = map(int, f.readline().strip().split(' '))
        for attack in xrange(n):
            day = d + attack * delta_d
            if day in days:
                days[day].append((tribe, attack))
            else:
                days[day] = [(tribe, attack)]
        statics[tribe] = (d, n, w, e, s, delta_d, delta_p, delta_s)
    result = attack_succ(days, statics)
    s = "Case #%d: %s\n" % (t+1, result)
    print s
    o.write(s)
    