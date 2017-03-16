T = int(input())

for i in range(1, T + 1):
    rr, t = map(int, input().split())
    def val(j):
        return (j * (j + 1) * (j + j + 1) // 6)

    def val2(j):
        if rr % 2 == 1:
            qq = rr-1+2*j
            return -val(qq) + 8 * val(qq//2) - (-val(rr-1) + 8 * val(rr//2))
        else:
            return val(rr - 1 + j * 2) - 8 * val(rr // 2 + j - 1) - (val(rr-1) - 8* val((rr-1)//2))

    ans = 0
    l = 1
    r = 10000000000000
    while l <= r:
        m = (l + r) // 2
        if val2(m) <= t:
            ans, l = m, m + 1
        else:
            r = m - 1
    
    print('Case #%d: %d' % (i, ans))
