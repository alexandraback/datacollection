from fractions import Fraction


def is_power2(num):
    return num != 0 and ((num & (num - 1)) == 0)


T = int(raw_input())

for case in range(T):
    f = Fraction(raw_input())
    for i in range(40):
        if not is_power2(f.denominator):
            print "Case #{}: impossible".format(case + 1)
            break
        if f >= 1.0/2**i:
            print "Case #{}: {}".format(case + 1, i)
            break
    else:
        print "Case #{}: impossible".format(case + 1)