import copy
fo = open('B-small-1.out', 'w')
data = open('B-small-attempt4.in').readlines()
data = data[1:]
num = int(len(data)) / 2

def resolve(raw):
    x = sorted(raw, reverse=True)
    m = x[0]
    if m <= 3:
        return m
    y = copy.deepcopy(x)
    y[0] = m - 3
    y.append(3)
    x[0] = m - m / 2 
    x.append(m / 2)
    return min(m, resolve(x) + 1, resolve(y) + 1)

for z in range(num):
    x = data[z * 2 + 1].split()
    x = [int(i) for i in x]
    res = resolve(x)
    s = 'Case #%d: %d' % (z + 1, res)
    print s
    fo.write(s + '\n')
                  