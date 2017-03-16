def solve(r, c, w):
    d, m = divmod(c, w)

    result = r * d

    result += w
    if m == 0:
        result -= 1
    return result


t = input()
for i in range(t):
    r, c, w = map(int, raw_input().split(' '))
    print 'Case #%d: %s' % (i + 1, solve(r, c, w))
