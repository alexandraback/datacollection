import fileinput

inp=fileinput.input()
line=inp.next()
T=int(line)

for case in xrange(T):
    line = inp.next()
    line=line.split(' ')
    N=int(line[0])
    Js=[]
    X=0
    for i in xrange(N):
        Js.append(int(line[i+1]))
        X+=int(line[i+1])
    #print Js
    mm=[]
    for y in Js:
        mm.append(1.0*y/X)
    mm.sort(reverse=True)
    
    #print mm
    for i in xrange(N):
        lvl=mm[i]
        integr=0.0
        for j in xrange(i,N):
            integr+=lvl-mm[j]
        #print integr
        if integr<=1.0:
            lvl+=(1.0-integr)/(N-i)
            break
    #print lvl
    
    ans=[]
    
    for J in Js:
        ans.append(max(0.0,lvl-1.0*J/X))
    #print ans
    
    s='Case #%s: '%(case+1)
    for a in ans:
        s+=str(a*100)+' '

    print s
    case+=1
    if case>T:
        break
