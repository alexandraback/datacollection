from collections import Counter as ct
fi = open("d.in")
t = int(fi.readline())
fo = open("out", "w")
for z in range(t):
    x,r,c= map(int, fi.readline().split())
    b=True
    if r*c%x!=0:
        b=False
    else:
        if x<=2:
            b=True
        elif x==3:
            b= r>=2 and c>=2
        elif x==4:
            b= r>=3 and c>=3
        elif x>=7:
            b=False
    fo.write("Case #%d: " % (z + 1))
    if b:
        fo.write("GABRIEL\n")
    else:
        fo.write("RICHARD\n")
fi.close()
fo.close()
print "Done"