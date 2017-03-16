n = int(raw_input())

def solve(values, e, r):
    if len(values) == 0:
        return [0] * (e + 1)
    sub = solve(values[1:], e, r)
    table = [0] * (e + 1)
    for i in range(e+1):
        maxval = 0
        for j in range(i+1):
            m = j * values[0] + sub[min(i - j + r, e)]
            maxval = max(maxval, m)
        table[i] = maxval
    return table

for i in range(n):
    (e, r, n) = map(int, raw_input().split())
    values = map(int, raw_input().split())
    table = solve(values, e, r)
    print 'Case #%d: %d' % ((i + 1), table[e])
