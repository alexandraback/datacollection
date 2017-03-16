import sys
#sys.stdin = open("a_example.in")

def to_ints(s):
    return map(int, s.split())

def schedule(activities, starting_energy, ending_energy, depth=0):
    if not activities:
        return 0

    pos, value = max(enumerate(activities), key=lambda x: (x[1], x[0]))

    total_spend = energy_max

    pos_pre_energy = min(energy_max, starting_energy + energy_regain * pos)
    pos_post_energy = max(0, ending_energy - (len(activities) - pos) * energy_regain)

    total_spend = pos_pre_energy - pos_post_energy

    total = total_spend * value

    #print "%sschedule %r %r %r %r %r = %d" % (' '*depth, activities[:pos], activities[pos], activities[pos+1:],
    #                                        starting_energy, ending_energy, total_spend)

    total += schedule(activities[:pos], starting_energy, pos_pre_energy, depth+1)
    total += schedule(activities[pos + 1:], pos_post_energy + energy_regain, ending_energy, depth+1)

    return total

energy_max, energy_regain = 4, 1
schedule([3, 1, 1, 3], 4, 0) == 12

n_cases = input()

for case in xrange(1, n_cases + 1):
    energy_max, energy_regain, n_activities = to_ints(raw_input())
    activities = to_ints(raw_input())

    #print energy_max, energy_regain

    out = schedule(activities, energy_max, 0)

    print "Case #%d: %s" % (case, out)
