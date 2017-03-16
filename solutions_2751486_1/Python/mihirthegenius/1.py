import re
import sys

fin = sys.stdin
fout = sys.stdout

def dotestcase(ii):
    a = 0
    b = 0
    c = 0
    line  = fin.readline().split()
    name = line[0]
    n = int(line[1])
    for jj in range(0, len(name), 1):
        if name[jj] in 'aeiou':
            a = 0
            pass
        else:
            a += 1
            pass
        if (a >= n):
            b = jj - n + 2
            pass
        c += b
        # fout.write('n = ' + str(n) + ', a = ' + str(a) + ', b = ' +
        # str(b) + ', c = ' + str(c) + '\n')
        pass
    fout.write('Case #' + str(ii + 1) + ': ' + str(c) + '\n')
    pass

T = int(fin.readline())
for ii in range (0, T, 1):
    dotestcase(ii)
    pass
