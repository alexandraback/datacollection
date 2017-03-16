f = open("in.txt","r")
g = open("out.txt","w")

for t in range(1,int(f.readline())+1):
    st = f.readline().strip("\n").split()
    a = int(st[0])
    b = int(st[1])
    ans = 0
    for j in range(a,b):
        st = str(j)
        l = []
        for i in range(1,len(st)):
            s = st[i:]+st[:i]
            if s[0]!='0':
                s2  = int(s)
                if s2>j and s2>=a and s2<=b and s2 not in l:
                    l.append(s2)
                    ans += 1
    g.write("Case #"+str(t)+": "+str(ans)+"\n")
f.close()
g.close()