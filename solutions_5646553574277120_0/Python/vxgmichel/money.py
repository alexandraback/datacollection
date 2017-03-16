"""Solve the 'Less Money, More Problems' problem."""

from solver import solver

def solve(c, s, v):
    r, l = 0, 0
    for x in s:
        while x > l+1:
            if l >= v:
                return r
            r += 1
            l += c * (l+1)
        l += c * x
    while True:
        if l >= v:
            return r
        r += 1
        l += c * (l+1)


@solver(lines_per_case=2)
def money(lines):
    c, _, v = arg = map(int, lines[0].split())
    s = sorted({int(x) for x in lines[1].split()})
    return solve(c, s, v)


if __name__ == "__main__":
    money.from_cli()
