import math
fi = open('d:\\codejam\\D-small-attempt0.in', 'rb')
fo = open('d:\\codejam\\dsmall_out.txt', 'wb')
T = int(fi.readline().replace('\n', ''))

for i in xrange(T):
    tmp = fi.readline().replace('\n', '')
    K, C, S = tmp.split(' ')
    K = int(K)
    C = int(C)
    S = int(S)
    fo.write('Case #%d: ' % (i+1))
    if K > C*S:
        fo.write('IMPOSSIBLE\r\n')
        continue
    fc = C * 1.0
    numS = int(math.ceil(K / fc))
    for i in xrange(numS):
        l = [(j+i*C)*(K**j) if j+i*C < K else 0 for j in xrange(C)]
        digitId = sum(l)+1
        fo.write(str(digitId) + ' ')
    fo.write('\r\n')
        
