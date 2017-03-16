def process(b, m):
    if m > 2**(b-2):
        return ('IMPOSSIBLE', [])

    matrix = []
    for i in range(b):
        if i == 0:
            matrix.append('0'*b)
        else:
            l = '0'*(i+1)
            l += '1'*(b-i-1)
            matrix.append(l)

    if m == 2**(b-2):
        l = '0'
        l += '1'*(b-1)
        matrix[0] = l
    else:
        l = '0'
        bs = "{0:b}".format(m)
        zeros = (b-2) - len(bs)
        l += '0'*zeros
        l += bs
        l += '0'
        matrix[0] = l

    return('POSSIBLE', matrix)
           

t = int(raw_input())
for i in xrange(1, t + 1):
    line = raw_input()
    [b, m] = map(lambda x: int(x), line.split(' '))
    (rv, matrix) = process(b, m)
    #print line
    print("Case #{}: {}".format(i, rv))
    if rv == 'POSSIBLE':
        for l in matrix:
            print l

