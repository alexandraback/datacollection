__author__ = 'Christian'

#fname = 'test_b.txt'
fname = 'B-small-attempt1.in'
#fname = 'B-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')

def find_slides(B,M):
    
    if M > 2**(B-2):
        return 'IMPOSSIBLE'
    
    res = []
    for i in range(B):
        l = []
        for j in range(B):
            l.append('0')
        res.append(l)
    
    
    #decompose M in powers of 2
    l = []
    while M:
        l.append(M % 2)
        M = M/2
        
    m = len(l)
    # build all links from B-1-m to B
    for i in range(B-1-m, B):
        for j in range(i+1, B):
            res[i][j] = '1'
            
    # then create direct links from 1 to B-1-ind if k is 1
    for ind, k in enumerate(l):
        if ind < B-2:
            if k:
                res[0][B-2-ind] = '1'
    
    return 'POSSIBLE\n' + ('\n'.join([''.join(x) for x in res]))
    
find_slides(2,1)

T = int(data[0])
for i in range(T):
    B, M = data[i+1].split(' ')
    B = int(B)
    M = int(M)
    res = find_slides(B,M)
    print >> res_file, "Case #%s: %s" % (i+1, res)
    
res_file.close()