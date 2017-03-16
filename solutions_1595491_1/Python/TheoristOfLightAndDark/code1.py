f = open("in.txt","r")
g = open("out.txt","w")
for t in range(1,int(f.readline())+1):
    st = f.readline().strip("\n").split()
    n = int(st[0])
    s = int(st[1])
    p = int(st[2])
    ans = 0
    l = []
    for i in range(n):
        w = int(st[3+i])
        if w==1 or w==0:
            if w>=p:
                ans+=1
        else:
           if w%3==0:
                hu = w/3
                if hu>=p:
                    ans+=1
                elif hu+1>=p and s>0:
                    ans+=1
                    s-=1
           if w%3==1 or w%3==2:
                hu = w/3
                if hu+1 >=p:
                    ans +=1
                elif hu+2 >=p and s>0:
                    ans+=1
                    s-=1
    g.write("Case #"+str(t)+": "+str(ans)+"\n")
f.close()
g.close()