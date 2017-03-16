from collections import Counter as ct
fi = open("b.in")
t = int(fi.readline())
fo = open("out", "w")
def add(k,v,d):
    if k in d:
        d[k]+=v
    else:
        d[k]=v
for z in range(t):
    d = int(fi.readline())
    l = map(int, fi.readline().split())
    mn=max(l)
    d=dict(ct(l))
    c=0
    while c<mn:
        x=max(d.keys())
        v=d.pop(x)
        h=x//2
        add(h,v,d)
        add(x-h,v,d)
        c+=v
        mn=min(mn,max(d.keys())+c)
    fo.write("Case #%d: %d\n" % (z + 1, mn))
fi.close()
fo.close()
print "Done"