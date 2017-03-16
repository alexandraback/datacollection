import sys

f = open(sys.argv[1], 'r')
lines = f.readlines()
T = long(lines[0])

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

for i in range(1, T + 1):
    rt = lines[i].split(' ')
    r = long(rt[0])
    t = long(rt[1])
    N = (isqrt(4 * r * r - 4 * r + 8 * t + 1) - 2 * r + 1) / 4;
    print "Case #{0}: {1}".format(i, N)

