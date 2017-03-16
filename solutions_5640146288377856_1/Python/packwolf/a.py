with open('A-large.in') as f:
    with open('a.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            line = f.readline()
            in_data = line.split(' ')
            [R, C, W] = map(lambda x: int(x), in_data)
            ships = (C+W-1)/W
            res = (R-1) * ships
            x = C % W > 0
            res += C/W + W - 1 + x
            print 'Case #{i}: {res}'.format(res=res, i=i)
            out.write('Case #{i}: {res}\n'.format(res=res, i=i))