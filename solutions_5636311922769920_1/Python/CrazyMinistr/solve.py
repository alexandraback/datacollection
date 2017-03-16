fi = open('in', 'r')
fo = open('out', 'w')

n = int(fi.readline())
for i in range(n):
    fo.write('Case #%d: ' % (i + 1))
    k, c, s = map(int, fi.readline().split())
    fo.write(' '.join([str(j) for j in range(1, s + 1)]) + '\n')
