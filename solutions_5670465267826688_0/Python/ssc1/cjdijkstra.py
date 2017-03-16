fi = open("c1.in")
t = int(fi.readline())
fo = open("out", "w")
d={'i':1,'j':2,'k':3}
ls=[[1,2,3,4],[2,-1,4,-3],[3,-4,-1,2],[4,3,-2,-1]]
def sa(x):
    if x>0:
        return x,1
    else:
        return -x,-1
for z in range(t):
    q,rp= map(int, fi.readline().split())
    l = map(lambda x:d[x], fi.readline().strip())*rp
    p=1
    c=0
    tg=[2,3,4]
    for i in l:
        a,b=sa(p)
        p=b*ls[a-1][i]
        if c<3 and p==tg[c]:
            c+=1
            p=1
    fo.write("Case #%d: " % (z + 1))
    if c==3 and p==1:
        fo.write("YES\n")
    else:
        fo.write("NO\n")
fi.close()
fo.close()
print "Done"