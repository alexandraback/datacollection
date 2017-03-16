import sys

def solve(k, c):
    spots = [i * k**(c-1) for i in range(k)]
    return [str(spot+1) for spot in spots]

next(sys.stdin)
case = 0
for line in sys.stdin:
    case += 1
    line = line.strip()
    k, c, s = [int(s) for s in line.split(' ')]
    print('Case #{}: {}'.format(case, ' '.join(solve(k, c))))
