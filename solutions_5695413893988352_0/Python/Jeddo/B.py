def func(C,J):
    big = 'U'
    res1 = ''
    res2 = ''
    for i in range(len(C)):
        a= C[i]
        b = J[i]
        ka = a!= '?'
        kb = b!= '?'
        if ka and kb:
            res1 += a
            res2 += str(b)
            if big == 'U'and (a!=b):
                if int(a)>int(b):
                    big = 'C'
                else:
                    big = 'J'     
        elif (not ka) and (not kb):
            if big =='U':
                res1 += '0'
                res2 += '0'
            elif big =='C':
                res1 += '0'
                res2 += '9'
            elif big == 'J':
                res1 += '9'
                res2 += '0'
        elif not ka:
            if big == 'U':
                res1 += str(b)
                res2 += str(b)
            elif big =='C':
                res1 += '0'
                res2 += str(b)
            elif big =='J':
                res1 += '9'
                res2 += str(b)
        elif not kb:
            if big == 'U':
                res1 += str(a)
                res2 += str(a)
            elif big =='C':
                res2 += '9'
                res1 += str(a)
            elif big =='J':
                res2 += '0'
                res1 += str(a)
    return res1,res2

inf = open('B-small.in','r')
out = open('B-small.out','w')

T = int(inf.readline())
for i in range(1,T+1):
    C,J= inf.readline().split(' ')
    res1,res2 = func(C,J)
    out.write('Case #%d: %s %s \n' %(i,res1,res2))
out.close()
inf.close()
