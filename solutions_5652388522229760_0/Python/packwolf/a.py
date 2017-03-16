with open('A-small-attempt0.in') as f:
    with open('A.out', 'w') as out:
        cases = int(f.readline())
        for i in xrange(1, cases+1):
            n = int(f.readline())
            nn = n
            digs = set(str(n))
            for j in range(1000):
                nn += n
                digs = digs.union(str(nn))
                if len(digs) == 10:
                    break

            if len(digs) == 10:
                print 'Case #{i}: {res}'.format(res=nn, i=i)
                out.write('Case #{i}: {res}\n'.format(res=nn, i=i))
            else:
                print 'Case #{i}: {res}'.format(res='INSOMNIA', i=i)
                out.write('Case #{i}: {res}\n'.format(res='INSOMNIA', i=i))