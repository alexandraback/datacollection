import fractions
in_f = open('A-small-attempt0.in', 'r')
out_f = open('A-small-attempt0.out', 'w')

t = int(in_f.readline())
for t in range(1, t+1):
    print 'processing %d case' % t
    out_f.write('Case #%d: ' % t)
    result = 0
    line = in_f.readline().split('/')
    p = int(line[0])
    q = int(line[1])
    gcd = fractions.gcd(p,q)
    p /= gcd
    q /= gcd
    if q & (q-1) != 0:
        out_f.write('impossible\n')
    else:
        while p < q:
            p *= 2
            result += 1
        out_f.write('%d\n' % result)
in_f.close()
out_f.close()
