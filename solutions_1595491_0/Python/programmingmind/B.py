def isSurp(a,b):
    if(a<b):
        return -1
    if(((3*(b-1))<a)):
        return 1
    if((3*b-5)>=a):
        return -1
    return 0
    
        

f = open('B-small-attempt0.in','r')
g = open('B-small.out','w')
a = f.read()
b = a.split(' ')
d = ""
for i in range(0,len(b)):
    d+=b[i]
    d+="\n"

b = d.split('\n')

c = []
for i in range(0,len(b)):
    if(len(b[i])>0):
        c.append((int)(b[i]))

cases = c[0]
current = 1

for i in range(0,cases):
    num = c[current]
    current+=1
    surprising  = c[current]
    current+=1
    target = c[current]
    current+=1
    P=0
    d = []
    S = 0
    for j in range(0,num):
        d.append(c[current])
        current+=1
    
    for j in range(0,len(d)):
        IS=isSurp(d[j],target)
        if(IS==1):
            P+=1
        elif(IS==0):
            S+=1
    if(S<surprising):
        P+=S
    else:
        P+=surprising

    g.write("Case #"+(str)(i+1)+": "+(str)(P)+"\n")

f.close()
g.close()
