import math

def tile(seq, base):
    res = 0
    mult = 1
    for x in reversed(seq):
        res += x * mult
        mult *= base
    return res

def solve(k, c, s):
    ranges = [list(range(i*c, min((i+1)*c, k))) for i in range(min(s, math.ceil(k/c)))]
    # print('ranges: ', ranges)
    tiles = list(map(lambda r: tile(r, k), ranges))
    # print('tiles: ', tiles)
    return list(map(lambda x: x+1, tiles))

t = int(input())
for i in range(t):
    k, c, s = map(int, input().split())
    if c * s < k:
        print('Case #{}: IMPOSSIBLE'.format(i+1))
    else:
        print('Case #{}: {}'.format(i+1, ' '.join(map(str, solve(k, c, s)))))

