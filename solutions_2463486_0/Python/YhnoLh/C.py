import math

def parlid(n):
    s = str(n)
    for i in range(len(s)):
        if s[i] != s[len(s) - 1 - i]:
            return False
    return True

p = []
for i in range(1, 10000000):
    if parlid(i) and parlid(i * i):
        p.append(i)

fi = open('C0.in', 'r')
fo = open('C.out', 'w')

tcase = int(fi.readline())
for icase in range(tcase):
    line = fi.readline().split()
    A = int(line[0])
    B = int(line[1])

    i = 0
    while p[i] * p[i] < A:
        i += 1
    j = i
    while j < len(p) and p[j] * p[j] <= B:
        j += 1

    fo.write('Case #%d: %d\n' % (icase + 1, j - i))

fi.close()
fo.close()
