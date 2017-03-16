class Tribe:
    def __init__(self, line):
        self.d, self.n, self.w, self.e, self.s, self.delta_d, self.delta_p, self.delta_s = (int(x) for x in line.split())

def solve(tribes):
    events = {}
    for tribe in tribes:
        day = tribe.d
        w = tribe.w
        e = tribe.e
        s = tribe.s
        for attack in range(tribe.n):
            events.setdefault(day, [])
            temp = events[day]
            temp.append((w, e, s))
            events[day] = temp
            w += tribe.delta_p
            e += tribe.delta_p
            s += tribe.delta_s
            day += tribe.delta_d
    wall = [0 for _ in range(1000000)]
    delta = len(wall) / 2
    days = events.keys()[:]
    days.sort()
    result = 0
    for day in days:
        raised = []
        for attack in events[day]:
            success = False
            for p in range(attack[0] + delta, attack[1] + delta):
                if wall[p] < attack[2]:
                    success = True
                    break
            if success:
                print attack, day
                result += 1
                raised.append((attack[0] + delta, attack[1] + delta, attack[2]))
        for r in raised:
            for p in range(r[0], r[1]):
                if wall[p] < r[2]:
                    wall[p] = r[2]
    return result

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    N = int(f.readline().strip())
    tribes = []
    for _ in range(N):
        tribes.append(Tribe(f.readline().strip()))
    result = solve(tribes)
    out.write("Case #%s: %s\n" % (test, result))
out.close()
