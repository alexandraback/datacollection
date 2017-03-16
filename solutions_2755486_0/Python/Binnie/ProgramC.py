import sys
from collections import defaultdict

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    N = int(f.readline())
    heights = defaultdict(int)
    tribes = []
    for ii in range(N):
        tribes.append(map(int, f.readline().strip().split()))
    
    all_days = []
    tribe_attack_days = []
    for tribe in tribes:
        days = []
        di = tribe[0]
        ni = tribe[1]
        delta_di = tribe[5]
        for attack in range(ni):
            days.append(di + attack * delta_di)
            all_days.append(di + attack * delta_di)
        tribe_attack_days.append(days)

    successful_attacks = 0
    all_days.sort()
    for day in all_days:
        wall_changes = []
        for ii in range(N):
            if day in tribe_attack_days[ii]:
                # tribe ii attacks today
                tribe = tribes[ii]
                di = tribe[0]
                delta_di = tribe[5]
                attack_num = (day - di) / delta_di
                assert(attack_num * delta_di + di == day)
                wi = tribe[2]
                ei = tribe[3]
                delta_pi = tribe[6]
                curr_wi = wi + attack_num * delta_pi
                curr_ei = ei + attack_num * delta_pi
                si = tribe[4]
                delta_si = tribe[7]
                curr_strength = si + attack_num * delta_si
                succ_attack = False
                for pos in range(curr_wi, curr_ei):
                    if heights[pos] < curr_strength:
                        successful_attacks += 1
                        succ_attack = True
                        break
                for pos in range(curr_wi, curr_ei):
                    wall_changes.append((pos, curr_strength))
        for (pos, strength) in wall_changes:
            heights[pos] = max(strength, heights[pos])


    print "Case #%d:" % (t + 1), successful_attacks
