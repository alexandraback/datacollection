import math

fo = open('A-small-1.out', 'w')
data = open('A-small-attempt5.in').readlines()
data = data[1:]
num = int(len(data))

def reverse_number(n):
    n = str(n)
    return int(n[::-1])

print reverse_number(10)

for z in range(num):
    n = int(data[z])
    res = 0
    if n < 20:
        res = n
    else:
        while n > 10:
            b = int(math.ceil(len(str(n)) * 1.0  / 2))
            c = int(math.floor(len(str(n)) * 1.0  / 2))
            x = n % (10 ** b)
            if x == 0:
                x = 10 ** c
            t = n - x + 1 
            res += (x - 1)
            n = t
            print t, n, res, x - 1, b
            t = reverse_number(t)
            if t >= n:
                n -= 1
            else:
                n = t
            print n
            res += 1
        res += n
    s = 'Case #%d: %d' % (z + 1, res)
    print s
    fo.write(s + '\n')