import sys

inp=sys.argv[1]
outp="%s.out" % inp.split(".")[0]

def hikers_data(inputs):
    hikers = []
    for pos, count, time in inputs:
        for dt in range(count):
            t = time + dt
            finish = (360 - pos) * t
            hikers.append((finish, "b"))
            _pos = pos
            for j in range(10): # TODO does not work for large
                _pos -= 360
                finish = (360 - _pos) * t
                hikers.append((finish, "a"))
    return hikers

#print(sorted(hikers_data([(90, 2, 1), (358, 1, 1)])))
def calc_encounters(time, hikers):
    res = 0
    for h in hikers:
        if time == h[0]: res += 1
        if time < h[0] and h[1] == "b": res += 1
        if time > h[0] and h[1] == "a": res += 1
    return res

def solve(inputs):
    hikers = sorted(hikers_data(inputs))
    minenc = len(hikers)
    for h in hikers:
        minenc = min(minenc, calc_encounters(h[0], hikers))
        minenc = min(minenc, calc_encounters(h[0]-0.5, hikers))
        minenc = min(minenc, calc_encounters(h[0]+0.5, hikers))
    return minenc

with open(inp, 'r') as f, open(outp, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        n = int(f.readline()[:-1])
        inputs = []
        for i in range(n):
            d, h, m = tuple([int(x) for x in f.readline()[:-1].split(" ")])
            inputs.append((d, h, m))
        out.write("Case #%s: %s\n" % (c+1,solve(inputs)))
