from solver import solver
from itertools import count


def rec(s):
    if all(s):
        return 0
    index = s.index(False)
    sub = [not x for x in s[index+1:]]
    return 1 + rec(sub)

@solver
def pancake(lines):
    s = [c=='+' for c in reversed(lines[0])]
    return rec(s)

if __name__ == '__main__':
    pancake.from_cli()
