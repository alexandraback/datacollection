from fractions import Fraction

T = int(raw_input())


def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)


for t in xrange(T):
    print "Case #%d:" % (t + 1),

    inp = raw_input().split("/")
    fr = Fraction(int(inp[0]), int(inp[1]))
    if is_power2(fr._denominator):
        frac = float(inp[0]) / float(inp[1])
        N = "impossible"
        for i in xrange(40):
            temp = pow(2, -(i + 1))
            if frac >= temp:
                N = i + 1
                break
    else:
        N = "impossible"
    print N