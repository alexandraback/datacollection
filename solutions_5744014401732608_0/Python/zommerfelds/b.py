
def get_log2(x):
    r = 1
    i = 0
    while r <= x:
        r <<= 1
        i += 1
    return i - 1
        

cases = int(input())
for c in range(cases):
    b, m = map(int, input().split())
    possible = (1 << (b - 2)) >= m
    print('Case #{}: {}'.format(c + 1, 'POSSIBLE' if possible else 'IMPOSSIBLE'))
    if not possible:
        continue
    p = get_log2(m)
    if b-2 > p:
        pp = m - (1 << p)
        print(
            '0' * (b-p-2) +
            '1' +
            (format(pp, '0{}b'.format(p)) if p > 0 else '') +
            '0'
        )
    for i in range(1, b-p-2):
        print('0' * b)
    for i in range(b-p-2, b):
        print('0' * (i + 1) + '1' * (b-i-1))
