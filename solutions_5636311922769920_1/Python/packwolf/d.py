import math
with open('D-large.in') as f:
    with open('D.out', 'w') as out:
        cases = int(f.readline())
        for i in xrange(1, cases+1):
            k, c, s = map(int, f.readline().split())
            if math.ceil(1.0 * k/c) <= s:
                res = []
                lpos = 0
                last = 0
                kk = 0
                pos = 0
                kpowc1 = k**(c-1)
                while kk < k:
                    cc = c
                    kpow = 1
                    pos = 0
                    while True:
                        last = pos
                        pos += kk*kpow
                        kpow *= k
                        kk += 1
                        cc -= 1
                        if cc <= 0:
                            res.append(pos)
                            # print 'c', kk, cc
                            break
                        if kk == k:
                            # print 'k'
                            res.append(pos + lpos)
                            break
                    lpos = kpowc1*kk
                # print k, c, s
                res = ' '.join(map(lambda x: str(x+1), res))
                print 'Case #{i}: {res}'.format(res=res, i=i)
                out.write('Case #{i}: {res}\n'.format(res=res, i=i))
            else:
                print 'Case #{i}: {res}'.format(res='IMPOSSIBLE', i=i)
                out.write('Case #{i}: {res}\n'.format(res='IMPOSSIBLE', i=i))