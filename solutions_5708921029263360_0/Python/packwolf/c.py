from collections import defaultdict
with open('C-small-attempt1.in') as f:
    with open('c.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            j, p, s, k = map(int, f.readline().split())
            jp = defaultdict(int)
            js = defaultdict(int)
            ps = defaultdict(int)
            res1 = []
            for ij in range(1, j+1):
                for ip in range(1, p+1):
                    for iis in range(1, s+1):
                        if js[(ij, iis)] < k and ps[(ip, iis)] < k and jp[(ij, ip)] < k:
                            res1.append((ij, ip, iis))
                            jp[(ij, ip)] += 1
                            js[(ij, iis)] += 1
                            ps[(ip, iis)] += 1
            res = [' '.join(map(str, line)) for line in res1]
            print j, p, s, k, #mx
            # print jp, js, ps
            print 'Case #{i}: {res}'.format(res=len(res), i=i)
            out.write('Case #{i}: {res}\n'.format(res=len(res), i=i))
            for j in res:
                print j
                out.write(str(j) + '\n')
