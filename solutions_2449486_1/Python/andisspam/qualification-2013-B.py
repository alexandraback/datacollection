import numpy as np

f_in = open('qualification-2013-B-large.dat', 'r')
n = int(f_in.readline())
f_out = open('qualification-2013-B.out', 'w')

for i in range(n):
    n, m = [int(item) for item in f_in.readline().strip().split(' ')]
    array = np.fromstring(' '.join(f_in.readline().strip() for j in range(n)), dtype = np.uint8, sep = ' ')
    array = array.reshape((n,m))
    rowmaxs = np.amax(array, axis = 1)
    colmaxs = np.amax(array, axis = 0)
    possible = True
    for row in range(n):
        for col in range(m):
            if array[row, col] < rowmaxs[row] and array[row, col] < colmaxs[col]:
                possible = False
    f_out.write('Case #%i: %s\n' % (i+1, 'YES' if possible else 'NO'))
