import sys

f = sys.stdin #open('C-small-practice.in')
def get_int(): return int(f.readline())
def get_ints(): return [int(s) for s in f.readline().split()]

def solve():
    [k, c, s] = get_ints()
    if c * s < k:
        return 'IMPOSSIBLE'
    i = 0
    res = []
    while i < k:
        res2 = 0
        for _ in range(min(c, k-i)):
            res2 = res2 * k + i
            i += 1
        res.append(res2+1)
    return ' '.join(map(str, res))

for t in range(get_int()):
    print('Case #%d:' % (t+1), solve())
