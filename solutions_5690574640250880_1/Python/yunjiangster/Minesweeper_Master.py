import sys
problems = []
for i,line in enumerate(sys.stdin):
    if i == 0:
        n = int(line.strip('\r\t\n '))
    else:
        problems.append(line.strip('\r\t\n '))
assert len(problems) == n
template="Case #%d:\n%s"
for q,p in enumerate(problems):
    R,C,M = [int(t) for t in p.split(' ')]
    u,v,w = R,C,M
    ret = []
    if R < C:
        invert = False
    else:
        invert = True
        tmp = R
        R = C
        C = tmp
    
    if R == 1:
        ret.append( ['c'] + ['.']*(R*C-M-1) + ['*']*M ) 
       
    elif R == 2:
        if M == R*C -1:
            ret.append(['c'] + ['*']*(C-1))
            ret.append(['*']*C)
        elif R*C - M > 3 and M % 2 == 0:
            k= (R*C - M)/2
            ret.append(['c'] + ['.']*(k-1) + ['*']*(C-k))
            ret.append(['.']*k + ['*']*(C-k))        
        else:
            ret = [['Impossible']]
    else:
        ret = [['*' for i in xrange(C)] for j in xrange(R)]
        x = R*C - M
        if x == 1: pass
        elif x == 4:
            for i in xrange(2):
                for j in xrange(2):
                    ret[i][j] = '.'
        elif x ==2 or (x%2 == 1 and x < 8):
            ret = [['Impossible']]
        else:
            if x <= 2 *C:
                if x % 2 == 1:
                    firstrow = (x - 3) / 2
                    for i in xrange(firstrow):
                        for j in xrange(2):
                            ret[j][i] = '.'
                    for i in xrange(3):
                        ret[2][i] = '.'
                else:
                    firstrow = (x -2 )/2
                    for i in xrange(firstrow):
                        for j in xrange(2):
                            ret[j][i] = '.'
                    for i in xrange(2):
                        ret[2][i] = '.'
               
            else:
                
                remainder = x - 2*C
                if remainder ==1:   
                    for i in xrange(C-1):
                        ret[0][i] = '.'
                        ret[1][i] = '.'
                    ret[2][0] = '.'
                    ret[2][1] = '.'
                    ret[2][2] = '.'
                else:
                    for i in xrange(C):
                        ret[0][i] = '.'
                        ret[1][i] = '.'
                    remainder = (x-2*C) % C
                    
                    for j in xrange((x - 2*C)/C):
                        for i in xrange(C):
                            ret[2+j][i] = '.'
                    for i in xrange(remainder):
                        ret[2+(x-2*C)/C][i]='.'
                    if remainder == 1:
                        ret[2+(x-2*C)/C - 1][-1] = '*'
                        for i in xrange(2):
                            ret[2 + (x - 2*C)/C][i] ='.'
    if not ret[0][0] == 'Impossible':            
        ret[0][0]='c'
        #pass
    if not invert:
        ret2= ret
    else:
        
        ret2= []
        R = len(ret)
        C = len(ret[0])
        for i in xrange(C):
            ret2.append([ret[j][i] for j in xrange(R)])
    if not ret[0][0] == 'Impossible':
        assert len(ret2) == u
        assert len(ret2[0]) == v
        assert [item for t in ret2 for item in t].count('*') == w
    print template%(q+1,'\n'.join([''.join(t) for t in ret2]))
                
            
       
