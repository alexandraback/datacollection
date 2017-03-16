"""Solve the '1CA' problem."""

from solver import solver


def solve(r, c, w):
    s = (c / w) * r + w
    return s if c % w else s - 1


@solver(lines_per_case=1)
def gcj_1ca(lines):
    r, c, w = map(int, lines[0].split())
    return solve(r, c, w)


if __name__ == "__main__":
    gcj_1ca.from_cli()
