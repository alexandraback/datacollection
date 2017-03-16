import sys
from collections import namedtuple

def read_int(fp=sys.stdin):
    return int(fp.readline().strip())

def read_ints(fp=sys.stdin):
    return map(int, fp.readline().strip().split())

MIN_W = -100
MAX_W = 100
OFFSET_W = 200

class Tribe:
    def __init__(self, day, number, west, east, strength, delta_d, delta_p, delta_s):
        self.day = day            # the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
        self.number = number      # the number of attacks from this tribe
        self.west = west          # the westmost and eastmost points respectively of the Wall attacked on the first attack
        self.east = east
        self.strength = strength  # the strength of the first attack
        self.delta_d = delta_d    # the number of days between subsequent attacks by this tribe
        self.delta_p = delta_p    # the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
        self.delta_s = delta_s    # the change in strength between subsequent attacks

def solve(tribes):
    wall = [0] * (MAX_W * 4)
    success = 0
    day = 0

    while day < 676060:
        next_day = None
        improve = []

        # print >>sys.stderr, "Day:", day

        for t, tribe in enumerate(tribes, 1):
            if tribe.day == day and tribe.number > 0:
                # print >>sys.stderr, "Tribe", t, "[", tribe.west, ",", tribe.east, "] strength =", tribe.strength
                win = False
                for i in range(tribe.west, tribe.east+1):
                    if wall[OFFSET_W + i] < tribe.strength:
                        improve.append((i, tribe.strength))
                        win = True
                        # print >>sys.stderr, "Succeeds at", i, "height =", wall[OFFSET_W + i]

                if win:
                    success += 1

                tribe.number -= 1
                tribe.day += tribe.delta_d
                tribe.west += tribe.delta_p
                tribe.east += tribe.delta_p
                tribe.strength += tribe.delta_s

            if tribe.number > 0 and (next_day is None or tribe.day < next_day):
                next_day = tribe.day

        if next_day is None:
            break
        day = next_day

        for i, s in improve:
            # Multiple attacks on same day!
            # Make sure not to raise and then lower again!
            if wall[OFFSET_W + i] < s:
                wall[OFFSET_W + i] = s

    return success

if __name__ == "__main__":
    T = read_int()
    for t in range(1, T+1):
        N = read_int()
        tribes = []
        for i in range(N):
            tribes.append(Tribe(*read_ints()))

        print "Case #%d: %s" % (t, solve(tribes))
