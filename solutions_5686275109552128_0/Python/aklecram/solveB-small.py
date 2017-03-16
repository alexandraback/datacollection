import sys

inp=sys.argv[1]
out="%s.out" % inp.split(".")[0]

def check(diners, time, specials):
    if time < 0: return False
    if max(diners) <= time: return True
    if specials == 0: return False
    i = diners.index(max(diners))
    diners[i] -= time - specials
    return check(diners, time-1, specials-1)

def search_small(diners, mint, maxt):
    for i in range(mint, maxt+1):
        for j in range(i+1):
            if check(list(diners), i, j):
                return i

with open(inp, 'r') as f, open(out, 'w') as out:
    cases = int(f.readline())
    for c in range(cases):
        f.readline()
        diners = [int(i) for i in f.readline().split(" ")]
        out.write("Case #%s: %s\n" % (c+1,search_small(diners, 0, max(diners))))
