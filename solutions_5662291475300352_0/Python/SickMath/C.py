f = open('small.in')
g = open('small.out', 'w')

T = int(f.readline()[:-1])

for case in range(T) :
    N = int(f.readline()[:-1])
    H = []
    for n in range(N) :
        d, h, m = map(int, f.readline()[:-1].split())
        for i in range(h) : H.append((d, m + i))
    maxtts = max(1. * m * (360 - d) / 360 for d, m in H)
    mintts = min(1. * m * (360 - d) / 360 for d, m in H)
    res = 0 if mintts + min(m for d, m in H) > maxtts else 1
    output = 'Case #' + str(case + 1) + ': ' + str(res)
    print output
    g.write(output + '\n')

f.close()
g.close()
