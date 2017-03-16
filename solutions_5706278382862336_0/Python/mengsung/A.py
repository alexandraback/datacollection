def gcd(m, n) :
    while m != 0 :
        m, n = n % m, m
    return n

def isPowerOf2(n) :
    power = 1
    while power < n :
        power *= 2
    return n == power

def solve(f) :
    a, b = f.readline().strip().split('/')
    a = int(a)
    b = int(b)
    common_divisor = gcd(a,b)
    a /= common_divisor
    b /= common_divisor

    if isPowerOf2(b) :
        generation = 0
        while a < b :
            a *= 2
            generation += 1
        return generation
    else :
        return 'impossible'


if __name__ == '__main__' :
    with open('A-small-attempt0.in') as f:
        t = int(f.readline())
        for i in range(t) :
            print ('Case #{0}: {1}'.format(i + 1, solve(f)))
