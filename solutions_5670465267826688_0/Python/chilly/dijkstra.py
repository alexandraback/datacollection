import math

M = {}
M[('1', '1')] = '1'
M[('1', 'i')] = 'i'
M[('1', 'j')] = 'j'
M[('1', 'k')] = 'k'

M[('i', '1')] = 'i'
M[('i', 'i')] = '-1'
M[('i', 'j')] = 'k'
M[('i', 'k')] = '-j'

M[('j', '1')] = 'j'
M[('j', 'i')] = '-k'
M[('j', 'j')] = '-1'
M[('j', 'k')] = 'i'

M[('k', '1')] = 'k'
M[('k', 'i')] = 'j'
M[('k', 'j')] = '-i'
M[('k', 'k')] = '-1'

with open('input', 'r') as f:
    num = int(f.readline().strip())
    for idx in xrange(1, num+1):
        L, X = map(int, f.readline().strip().split(' '))
        string = f.readline().strip()
        tmp = '1'
        sign = 1
        for i in xrange(L):
            if len(tmp) == 2:
                sign *= -1
                tmp = tmp[1]
            tmp = M[(tmp, string[i])]

        status = 'i'
        tmp = '1'
        sign = 1
        for x in xrange(X):
            for i in xrange(L):
                if len(tmp) == 2:
                    sign *= -1
                    tmp = tmp[1]
                if tmp == 'i' and sign == 1 and status == 'i':
                    status = 'j'
                    tmp = '1'
                if tmp == 'j' and sign == 1 and status == 'j':
                    status = 'k'
                    tmp = '1'
                tmp = M[(tmp, string[i])]

        if len(tmp) == 2:
            sign *= -1
            tmp = tmp[1]

        if status == 'k' and sign == 1 and tmp == 'k':
            print 'Case #' + str(idx) + ': YES'
        else:
            print 'Case #' + str(idx) + ': NO'
