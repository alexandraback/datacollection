import sys

inp=sys.argv[1]
out="%s.out" % inp.split(".")[0]

def _solve2(x, r, c):
    if x >= 7: return False
    if (r*c) == 0: return False
    if (r*c)%x != 0: return False
    if max(r, c) < x: return False
    if x == 3 and min(r, c) < 2: return False
    if x == 4 and min(r, c) <= 2: return False
    if x == 5:
        if max(r, c) == 5 and min(r, c) <= 3: return False
    if x == 6 and min(r, c) <= 3: return False
    return True

def solve(x, r, c):
    return "GABRIEL" if _solve2(x, r, c) else "RICHARD"

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for case in range(cases):
        x, r, c = tuple([int(i) for i in f.readline().split(" ")])
        out.write("Case #%s: %s\n" % (case+1, solve(x, r, c)))
