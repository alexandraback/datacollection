def func(B,M):
    if pow(2,B-2)< M:
        return 'IMPOSSIBLE',None
    tem = bin(M-1)[2:].zfill(B-2)
    if B-2 == 0:
        tem = ''
    res=['0'+tem+'1']
    for i in range(B-2):

        res.append('0'+(i+1)*'0'+(B-2-i)*'1')
        
    res.append('0'*B)   
    
    return 'POSSIBLE',res

inf = open('B-small.in','r')
out = open('B-small.out','w')

T = int(inf.readline())
for i in range(1,T+1):
    B,M = map(int,inf.readline().split(' '))
    p,res = func(B,M)
    out.write('Case #%d: %s \n' %(i,p))
    if p == "POSSIBLE":
        for i in res:
            out.write(i+'\n')
out.close()
inf.close()
