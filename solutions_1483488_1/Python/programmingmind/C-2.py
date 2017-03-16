def Rec(a):
    s = str(a)
    r = []
    t = s
    L = 1
    while((t!=s) or L==1):
    #for i in range(0,len(s)):
        L=0
        t = t[len(t)-1] + t[0:len(t)-1]
        r.append((int)(t))
    return r

f = open('C-large.in','r')
g = open('C-large.out','w')
a = f.read()
a = a.replace('\n'," ")
b = a.split(' ')

c = []
for i in range(0,len(b)):
    if(len(b[i])>0):
        c.append((int)(b[i]))

cases = c[0]
current = 1

count = 0

for i in range(0,cases):
    low = c[current]
    current+=1
    high = c[current]
    current += 1

    count = 0

    for j in range(low,high+1):
       t = Rec(j)
       for k in range(0,len(t)):
            if((t[k]<=high) and (t[k]>j)):
                count+=1

    g.write("Case #"+(str)(i+1)+": "+(str)(count)+"\n")

f.close()
g.close()
