f = open("in.txt","r")
g = open("out.txt","w")

t = int(f.readline().strip())
for id in range(1,t+1):
    ans = 0
    star = 0
    poss = 1
    n = int(f.readline())
    d = []
    c = []
    p1,p2 = [],[]
    for j in range(n):
        a = f.readline().split()
        c.append(int(a[0]))
        d.append(int(a[1]))
        p1.append(0)
        p2.append(0)
    if id ==6:
        print n,c,d
    cont = 0
    while 1:
        cont = 0
        for j in range(n):
            if p1[j]==0 and d[j]<=star:
                ans += 1
                star += 2
                p1[j] = 1
                p2[j] = 1
                cont = 1
                j = n
        if cont == 0:
            for j in range(n):
                who = 1
                if p1[j]==0 and c[j]<=star:
                    p1[j] = 1
                    star += 1
                    ans += 1
                    cont =1
                    j = n
                    break
                    who = 0
                if (p2[j]==0) and d[j]<=star and who==1:
                    p2[j]=1
                    ans+=1
                    star += 1
                    cont = 1
                    j = n
                    break
        if cont == 0:
            break
    poss = 1
    for j in range(n):
        if p2[j]==0:
            poss = 0
    if poss == 1:
        g.write("Case #"+str(id)+": "+str(ans)+"\n")
    else:
        g.write("Case #"+str(id)+": Too Bad\n")
f.close()
g.close()