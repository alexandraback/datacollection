def solve(s):
    t = ''
    for c in s:
        if c + t > t + c:
            t = c + t
        else:
            t = t + c
    return t

t = int(raw_input())
for i in range(1, t + 1):
    s = raw_input()
    print 'Case #{}: {}'.format(i, solve(s))
