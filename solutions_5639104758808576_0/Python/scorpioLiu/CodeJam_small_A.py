fo = open('A-small-1.out', 'w')
data = open('A-small-attempt0.in').readlines()
print (data)
num = int(data[0].strip())
for z in range(num):
    res = 0
    raw = data[z + 1].strip().split()[1]
    x = 0
    for i in range(len(raw)):
        n = int(raw[i])
        if i == 0:
            x = n
        else:
            if i > x:
                res += (i - x)
                x += (i - x)
            x += n

    s = 'Case #%d: %d' % (z + 1, res)
    print (s)
    fo.write(s + '\n')          