import sys

infile = sys.stdin

class Attack(object):
    def __init__(self, begin, end, power, day):
        self.begin = begin
        self.end = end
        self.power = power
        self.day = day

    def is_success(self, wall):
        for pos in xrange(self.begin * 2, self.end * 2 + 1):
            if wall[pos] < self.power:
                return True
        return False

    def update_wall(self, wall):
        for pos in xrange(self.begin * 2, self.end * 2 + 1):
            wall[pos] = max(wall[pos], self.power)

def init():
    wall = [0] * 5000
    attacks = dict()

    tribe_count = int(infile.readline())
    for i in range(tribe_count):
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si = [int(item) for item in infile.readline().split()]
        day = di
        power = si
        begin = wi
        end = ei
        
        for j in xrange(ni):
            cur = Attack(begin, end, power, day)
            day_attacks = attacks.get(day, [])
            day_attacks.append(cur)
            attacks[day] = day_attacks

            day += delta_di
            power += delta_si
            begin += delta_pi
            end += delta_pi

    return attacks, wall

def solve():
    attacks, wall = init()
    days = sorted(attacks.keys())
    count = 0
    for day in days:
        day_attacks = attacks[day]

        for attack in day_attacks:
            succ = attack.is_success(wall)
            # print "day %d, power: %d, from: %d, to: %d, %d" % (attack.day,
            #                                                    attack.power,
            #                                                    attack.begin, attack.end,
            #                                                    succ)
            count += succ
        for attack in day_attacks:
            attack.update_wall(wall)
    return count

if __name__ == "__main__":
    T = int(infile.readline())
    for i in range(T):
        ret = solve()
        print "Case #%d: %d" % (i+1, ret)
