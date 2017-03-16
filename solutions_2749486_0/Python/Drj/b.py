

c = "Case #"

f = open('b.txt')
g = open('bout.txt','w')
t = int(f.readline())

for i in range(t):
    m = f.readline().split()
    x = int(m[0])
    y = int(m[1])
    s = ''
    if(x<=0 and y>=0):
        x = abs(x)
        for j in range(x):
            s+="EW"
        for k in range(y):
            s+="SN"
    elif(x<=0 and y<=0):
        x = abs(x)
        y = abs(y)
        for j in range(x):
            s+="EW"
        for k in range(y):
            s+="NS"
    elif(x>=0 and y<=0):
        for j in range(x):
            s+="WE"
        y = abs(y)
        for k in range(y):
            s+="NS"
    else:
        for j in range(x):
            s+="WE"
        for k in range(y):
            s+="SN"
    z = c+str(i+1)+": "+s+'\n'
    #print z.strip()
    g.write(z)
f.close()
g.close()
