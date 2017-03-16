import sys
import heapq

inp=sys.argv[1]
out="%s.out" % inp.split(".")[0]

def check(diners, time, specials):
    t = time
    s = specials
    rdiners = list([-d for d in diners])
    heapq.heapify(rdiners)
    while True:
        if t < 0: return False
        if abs(rdiners[0]) <= t: return True
        if s == 0: return False
        m = abs(heapq.heappop(rdiners))
        heapq.heappush(rdiners, -(m-time+specials))
        t -= 1
        s -= 1

def search(diners, mint, maxt, specials):
    if mint+1 >= maxt:
        return mint if check(diners, mint, specials) else maxt
    middle = (mint+maxt)//2
    if check(diners, middle, specials):
        return search(diners, mint, middle, specials)
    return search(diners, middle, maxt, specials)

def search2(diners, mint, maxt):
    time = maxt
    for s in range(0, max(diners)+1):
        time = min(time, search(diners, s, maxt, s))
    return time

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        f.readline()
        diners = [int(i) for i in f.readline().split(" ")]
        out.write("Case #%s: %s\n" % (c+1,search2(diners, 0, max(diners))))
        print("Case #%s: %s" % (c+1,search2(diners, 0, max(diners))))
