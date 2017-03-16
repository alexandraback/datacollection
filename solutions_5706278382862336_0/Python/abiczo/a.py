def gcd(a, b):
    if a == 0 or b == 0:
        return a + b
    return gcd(b, a % b)

if __name__ == '__main__':
    MAX_LEVEL = 40

    for caseno in xrange(int(raw_input())):
        p, q = [int(s) for s in raw_input().split('/')]
        g = gcd(p, q)
        p = p / g
        q = q / g

        k = 1
        while k <= MAX_LEVEL:
            # if p/q >= 1/(2**k)
            if p * (2 ** k) >= q:
                break
            k += 1
        m = 0
        while m <= MAX_LEVEL:
            if q == 2 ** m:
                break
            m += 1
        sol = str(k) if m <= MAX_LEVEL else "impossible"
        print 'Case #%d: %s' % (caseno + 1, sol)
