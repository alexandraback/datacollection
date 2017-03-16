from math import sqrt, pow, floor, ceil

if __name__ == "__main__":
    f = open('3.in', 'r')
    o = open('3.out', 'w')

    T = int(f.readline().strip())

    for t in xrange(T):
        (A, B) = map(int, f.readline().strip().split(' '))
        fair_count = 0
        a = int(ceil(sqrt(A)))
        b = int(floor(sqrt(B)))
        for num in range(a, b + 1):
            if str(num) == str(num)[::-1]:
                sq = int(pow(num, 2))
                if str(sq) == str(sq)[::-1]:
                    fair_count = fair_count + 1

        s = "Case #%s: %s\n" % (t + 1, fair_count)
        o.write(s)
