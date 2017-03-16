"""Solve the 'Typewriter Monkey' problem."""

from solver import solver

def proba(c, a, t):    
    p = 1.0
    for x, y in zip(c, t):
        if x == y:
            continue
        if x != "?":
            return 0.0
        p *= a.count(y)
        p /= len(a)
    return p

def rec2(c, a, t):
    c = list(c)
    if len(c) < len(t):
        return 0
    p = proba(c, a, t)
    if not p:
        return rec2(c[1:], a, t)
    c = list(c)
    for i, x in enumerate(t):
        c[i] = x
    return 1 + rec2(c[1:], a, t)
    
def rec(c, a, t):
    c = list(c)
    if len(c) < len(t):
        return 0.0
    p = proba(c, a, t)
    r = (1 - p) * rec(c[1:], a, t)
    if not p:
        return r
    c = list(c)
    for i, x in enumerate(t):
        c[i] = x
    return r + p * (1 + rec(c[1:], a, t))

def solve(length, alphabet, target):
    current = ["?"] * length
    total = rec2(current, alphabet, target)
    return total - rec(current, alphabet, target)
    


@solver(lines_per_case=3)
def typewriter(lines):
    _, _, length = arg = map(int, lines[0].split())
    alphabet, target = lines[1].strip(), lines[2].strip()
    return solve(length, alphabet, target)


if __name__ == "__main__":
    typewriter.from_cli()
