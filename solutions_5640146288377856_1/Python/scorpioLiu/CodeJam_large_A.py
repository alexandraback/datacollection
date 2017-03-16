import math

fo = open('A-large.out', 'w')
data = open('A-large.in').readlines()
data = data[1:]
num = int(len(data))

def find(r, c, w):
    res = w
    a = c / w
    b = c % w
    if b > 0:
        res  += 1
    if a > 0:
        res += (a - 1)
        res += a * (r - 1)
    
    return res



for z in range(num):
    n = [int(i) for i in data[z].split()]
    r, c, w = n[0], n[1], n[2]
    res = find(r, c, w)
    s = 'Case #%d: %d' % (z + 1, res)
    print s
    fo.write(s + '\n')
