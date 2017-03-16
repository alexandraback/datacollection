def to_base_k(x, k):
    res = []

    while (x != 0):
        res.append(x % k)
        x /= k

    return ''.join(map(str, res[::-1]))


t = int(raw_input())


for tt in xrange(t):
    n, num_needed = map(int, raw_input().split())

    k = n - 2 

    total = 0
    done = False

    found = []

    for r in xrange(2 ** k):
        num = '1' + to_base_k(r, 2).zfill(k) + '1'

        valid = True

        divisors = []

        for b in xrange(2, 11):
            xx = int(num, b)

            for l in xrange(1, 10):
                if (xx % (2 * l + 1) == 0 and xx != 2 * l + 1):
                    divisors.append(2 * l + 1)

                    break

            if (len(divisors) == 9):
                found.append((xx, divisors))

                total += 1

                if (total == num_needed):
                    done = True
                    break

        if (done):
            break

    print 'Case #%d:' % (tt + 1)

    for num, divs in found:
        print num, 
        for div in divs:
            print div,
        print
