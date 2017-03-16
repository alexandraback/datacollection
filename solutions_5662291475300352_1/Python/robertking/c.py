from fractions import Fraction as f

data = iter(open('C-small-2-attempt0.in').read().splitlines())
cases = int(next(data))

def deer_times(d, m):
    times = []
    d = 360 - d
    for laps in range(12):
        times.append(f((360 * laps + d) * m, 360))
    return times

def get_times(deer):
    times = []
    first_times = []
    for group in deer:
        d, h, m = group
        for di in range(h):
            ts = deer_times(d, m + di)
            first_times.extend([ts[0]])
            times.extend(ts[1:])
    return times, first_times

def solve(deer):
    times, first_times = get_times(deer)
    times.sort()
    first_times.sort()
    ans = 999999
    for t in first_times:
        overtook = 0
        for tt in first_times:
            if tt > t:
                overtook += 1
        passed = 0
        for t2 in times:
            if t2 <= t:
                passed += 1
        #print overtook, passed, t
        ans = min(ans, overtook + passed)
    return ans



for case in range(1, cases + 1):
    n = int(next(data))
    deer = []
    for _ in range(n):
        d, h, m = map(int, next(data).split())
        deer.append((d, h, m))
    print "Case #%d: %d" % (case, solve(deer))


