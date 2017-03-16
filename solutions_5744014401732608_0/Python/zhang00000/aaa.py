import math
import numpy as np


fin = open('B-small-attempt0.in', 'r')
fout = open('B1.out', 'w')

alist = fin.read().splitlines()
t = int(alist[0])
fileindex = 1
for ii in range(1, t+1):
    b, m = [int(s) for s in alist[fileindex].split(' ')]

    # n = int(alist[fileindex])
    # s = alist[fileindex+1: fileindex+n+1]
    # fileindex += n
    out = ''
    if 2**(b-2) < m:
        out += 'IMPOSSIBLE\n'
    else:
        out += 'POSSIBLE\n'
        matrix = ['0'*b]*b

        b1 = math.ceil(math.log2(m))+1
        for i in range(b-1):
            if i<b1:
                matrix[i] = '0' * (i + 1) + '1' * (b1 -i  ) + '0'*(b-b1-1 )
            else:
                matrix[i] = '0' * (i +1) + '1' + '0' * (b - i -2)
        y = bin(m-1)[2:]
        if m>1:
            matrix[0] = '0'+ y + '1'+'0'* (b-len(y)-2)

        for item in matrix:
            out += item + '\n'

    fileindex += 1
    print("Case #{}: {}".format(ii, out))
    fout.write("Case #{}: {}".format(ii, out))
