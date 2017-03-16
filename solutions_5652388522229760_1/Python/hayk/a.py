import sys
import numpy as np

a = np.loadtxt(sys.argv[1]).astype('int')
a = a[1:]

with open('a.out', 'w') as f:
    case = 1
    for x in a:
        f.write('Case #%d: ' % case)
        case += 1

        if x == 0:
            f.write('INSOMNIA\n')
        else:
            t = np.zeros(10, dtype='bool')
            n = x
            while True:
                digits = np.array(map(int, list(str(n))), dtype='int')
                t[digits] = 1
                if t.sum() == 10:
                    break
                n += x
   
            f.write(str(n) + '\n')

