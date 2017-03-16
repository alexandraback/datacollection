from math import floor, sqrt

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def re(r, t):
    delta_root = isqrt((2 * r + 3) * (2 * r + 3) + 8 * (t - 2 * r - 1))
    k = (delta_root - 2 * r - 3) / 4
    if (2 * r + 3) * k + 2 * k * k + 2 * r + 1 > t:
        print 'TOO BIG'
    if (2 * r + 3) * (k + 1) + 2 * (k + 1) * (k + 1) + 2 * r + 1 <= t:
        print 'TOO SMALL'
    return k

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        r, t = map(int, raw_input().split())
        print 'Case #%d: %s' % (i + 1, 1 + re(r, t))
