f = open('in', 'r')
fo = open('out', 'w')

n = int(f.readline())
for i in range(n):
    x = int(f.readline())
    if x == 0:
        fo.write('Case #%d: INSOMNIA\n' % (i + 1))
        continue

    a = [0] * 10
    for j in range(1, 10000):
        y = x * j
        while y:
            a[y % 10] = 1
            y /= 10

        if sum(a) == 10:
            fo.write('Case #%d: %d\n' % ((i + 1), x * j))
            break
