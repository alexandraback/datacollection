fi=open("al.in")
t=int(fi.readline())
fo=open("b","w")
for z in range(t):
    (a,b)= fi.readline().split()
    a=int(a)
    b=map(int, b)
    c=0
    t=0
    for i,j in enumerate(b):
        c+=max(i-t,0)
        t=max(i,t)
        t+=j
    fo.write("Case #%d: %d\n"%(z+1,c))
fi.close()
fo.close()
print "Done"