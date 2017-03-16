import math
fout = open('b.out', 'w')
fin = open('B-small-attempt0.in', 'r')

t = int(fin.readline())
for x in range(1,t+1):
    s = fin.readline().split(" ")
    b = int(s[0])
    m = int(s[1])
    if math.pow(2,b-2) < m:
        fout.write('Case #{}: IMPOSSIBLE\n'.format(x))
    else:
        fout.write('Case #{}: POSSIBLE\n'.format(x))
        fout.write(bin(m-1)[2:].zfill(b-1))
        fout.write('1\n')

        for y in range(2,b+1):
            fout.write('{}{}\n'.format('0'*y, '1'*(b-y)))
