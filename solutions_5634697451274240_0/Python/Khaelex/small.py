import sys

def solve(s):
    good=True
    num_ops = 0
    for c in reversed(s):
        if c == '+':
            if not good:
                good = True
                num_ops += 1
        if c == '-':
            if good:
                good = False
                num_ops += 1
    return num_ops

next(sys.stdin)
case = 0
for s in sys.stdin:
    case += 1
    print('Case #{}: {}'.format(case, solve(s.strip())))
