def solve():
    R, C, W = map(int, raw_input().split())
    t = C / W
    if C % W == 0:
        return t * R + W - 1
    else:
        return t * R + W

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
