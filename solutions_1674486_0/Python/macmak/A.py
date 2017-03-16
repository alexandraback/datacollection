import fileinput

inp=fileinput.input()
line=inp.next()
T=int(line)

def gonext(path,cur,been):
    if cur in been:
        return True
    been.add(cur)
    for nxt in path[cur]:
        if gonext(path,nxt,been):
            return True
    return False
    

for case in xrange(T):
    line=inp.next()
    N=int(line)

    path={}
    for i in xrange(N):
        line=inp.next()
        inputs=line.split(' ')
        M=int(inputs[0])
        togo=[]
        for j in xrange(M):
            togo.append(int(inputs[j+1]))
            
        path[i+1]=togo
    #print path
    loop=False
    for i in path:
        if gonext(path,i,set()):
            loop=True
    
    if loop:
        st='Yes'
    else:
        st='No'

    print 'Case #%s: %s'%(case+1,st)
    if case+1>T:
        break
