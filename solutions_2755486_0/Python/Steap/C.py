import sys
from math import pi

class Interval(object):
    def __init__(self, w, e, s):
        self.w = w
        self.e = e
        self.s = s

    def __repr__(self):
        return "([%d, %d] %d)" % (self.w, self.e, self.s)
        
    def __str__(self):
        return "[%d, %d] %d" % (self.w, self.e, self.s)

def add_interval_to_wall(interval, wall):
    start = interval[0]
    stop = interval[1]

    
def solve(data):
    planning_d = {}
    n_tribes = int(data.pop(0).strip())
    for i in range(n_tribes):
        raw = data.pop(0).strip().split(" ")
        d = int(raw[0])
        n = int(raw[1])
        w = int(raw[2])
        e = int(raw[3])
        s = int(raw[4])
        delta_d = int(raw[5])
        delta_p = int(raw[6])
        delta_s = int(raw[7])
        for i in range(n):
            day = d + i * delta_d
            interval = [w + i * delta_p, e + i * delta_p]
            strength = s + i * delta_s
            #print("Attack %d %s %d" % (day, interval, strength))
            x = Interval(interval[0], interval[1], strength)
            if not planning_d.has_key(day):
                planning_d[day] = []
            planning_d[day].append(x)


    # Attacks
    def explode(i):
        a = i.w
        b = i.e
        return [Interval(x,x+1,i.s) for x in range(a, b)]

    def same_brick(x, y):
        return x.w == y.w and x.e == y.e

    def can_attack(expl, wall):
        found = [False for _ in range(len(expl))]
        for i, ex in enumerate(expl):
            for brick in wall:
                if same_brick(ex, brick):
                    found[i] = True
                    if ex.s > brick.s:
                        return True

        if False in found:
            return True

        return False

    wall = []
    total = 0
    import collections
    od = collections.OrderedDict(sorted(planning_d.items()))
    #for day, intervals in planning_d.items():
    for day, intervals in od.items():
#        print "Wall ", wall
#        print "Total", total
        for interval in intervals:
            expl = explode(interval)
            if can_attack(expl, wall):
                total += 1
                continue
        # Build
        for interval in intervals:
            expl = explode(interval)
            for ex in expl:
                found = False
                for brick in wall:
                    if same_brick(brick, ex):
                        found = True
                        if brick.s < ex.s:
                            brick.s = ex.s
                if found == False:
                    wall.append(ex)
            
        
    return total

def main():
    data = sys.stdin.readlines()
    T = int(data.pop(0).strip())
    for i in range(1,T+1):
        res = solve(data)
        print("Case #%d: %d" % (i, res))

if __name__ == '__main__':
    main()
