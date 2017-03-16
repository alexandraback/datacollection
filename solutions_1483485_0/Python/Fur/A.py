fin = open('1.in', 'r')
fout = open('1.out', 'w')
a = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '\n']
b = ['y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', ' ', '\n']
f = dict([(x, y) for x, y in zip(a, b)])
T = int(fin.readline())
for case in xrange(1, T + 1):
    line = fin.readline()
    fout.write('Case #' + str(case) + ': ')
    for x in line:
        fout.write(f[x])
    
