f = open("in.txt","r")
g = open("out.txt","w")

unv = []
for j in range(1,2000000):
        st = str(j)
        l = []
        for i in range(1,len(st)):
            s = st[i:]+st[:i]
            if s[0]!='0':
                s2  = int(s)
                if s2>j and s2>=1 and s2<=2000000 and s2 not in l:
                    l.append(s2)
        unv.append(l)

for t in range(1,int(f.readline())+1):
    st = f.readline().strip("\n").split()
    a = int(st[0])
    b = int(st[1])
    ans = 0
    for j in range(a,b):
        for k in unv[j-1]:
            if k<=b and k>=a:
                ans += 1
    g.write("Case #"+str(t)+": "+str(ans)+"\n")
    print t
f.close()
g.close()