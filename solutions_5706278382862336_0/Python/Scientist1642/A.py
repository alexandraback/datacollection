
T = int(raw_input())

def gcd(a , b):
    if b == 0:
        return a
    return gcd(b, a % b)


for t in xrange(T):
    cs = 'Case #' + str(t + 1) + ':'
    a, b = map(int, raw_input().split('/'))
    g = gcd(a, b)
    a /= g
    b /= g
    if a == b == 1:
        print cs, 0
    if (b & (b - 1) != 0):
        print cs, 'impossible'
        continue
    ans = 0
    while (2 * a - b < 0):
        ans += 1
        b /= 2
    print cs, ans + 1