from math import sqrt, pow, floor, ceil
# import itertools

if __name__ == "__main__":
    f = open('3.in', 'r')
    o = open('3.out', 'w')

    all_fair_pals = []
    for a in range(1, int(pow(10, 7)) + 1):
        a_s = str(a)
        if a_s == a_s[::-1]:
            sq = str(int(pow(a, 2)))
            if sq == sq[::-1]:
                all_fair_pals.append(a)

    T = int(f.readline().strip())

    for t in xrange(T):
        (A, B) = map(int, f.readline().strip().split(' '))
        fair_count = 0
        a = int(ceil(sqrt(A)))
        b = int(floor(sqrt(B)))
        # fair_count = fair_pal_count_in_range(a, b)
        fair_count = len([num for num in all_fair_pals if num >= a and num <= b])

        s = "Case #%s: %s\n" % (t + 1, fair_count)
        o.write(s)
