import sys

inp=sys.argv[1]
out="%s.out" % inp.split(".")[0]

def _solve(x, r, c):
    if r * c <= 0: return False
    if x == 1:
        return True
    if x == 2:
        return (r * c) % 2 == 0
    if x == 3:
        return (r * c) % 3 == 0 and r > 1 and c > 1
    if x == 4:
        return r * c == 12 or r * c == 16

def solve(x, r, c):
    return "GABRIEL" if _solve(x, r, c) else "RICHARD"

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for case in range(cases):
        x, r, c = tuple([int(i) for i in f.readline().split(" ")])
        out.write("Case #%s: %s\n" % (case+1, solve(x, r, c)))
