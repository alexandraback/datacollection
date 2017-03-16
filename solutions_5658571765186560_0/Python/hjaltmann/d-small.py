import sys

def sol(x, r, c):
    impossible = (r * c % x != 0 or
        (r < x and c < x) or
        ((x + 1) // 2 > min(r,c)) or
        (x == 4 and r * c == 8))

    return 'GABRIEL' if not impossible else 'RICHARD'

for i, line in enumerate(sys.stdin.read().splitlines()[1:]):
    seq = tuple(map(int,line.split()))
    print('Case #%s:' % (i+1), sol(*seq))
