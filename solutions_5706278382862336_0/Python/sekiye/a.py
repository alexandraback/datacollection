import fractions

def is_power2(n):
    while n > 1:
        if n % 2 != 0:
            return False
        n /= 2
    return True

def solve():
    P, Q = map(int, raw_input().split('/'))
    f = fractions.Fraction(P, Q)
    if not is_power2(f.denominator):
        return 'impossible'
    a = f.denominator
    b = f.numerator
    count = 0
    count2 = 0
    while a > 1:
        if b >= 1:
            count += 1
        count2 += 1
        b /= 2
        a /= 2
    return count2 - count + 1

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
