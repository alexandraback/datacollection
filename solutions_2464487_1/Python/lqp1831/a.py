T = input()
i = 0
while T > 0:
    T -= 1
    i += 1
    r, t = map(int, raw_input().split(" "))
    L = 0
    R = 10000000000000000L
    while L + 1 < R:
        mid = (L + R) / 2
        need = 2 * r * mid - 3 * mid + 2 * mid * (mid + 1)
        if need <= t : L = mid
        else : R = mid
    print "Case #%d:"%i, L

