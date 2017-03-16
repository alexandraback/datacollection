f = open('A-small-attempt1.in', 'r')
f2 = open('A-small-attempt1.out', 'w')

n=int(f.readline())

for i in range(n):
    seen=[0]*10
    c=0
    a=int(f.readline())
    if a==0:
        f2.write("Case #"+str(i+1)+": INSOMNIA\n")
    else:
        x=0
        while(c!=10):
            x+=a
            t=str(x)
            for l in t:
                l=int(l)
                if not seen[l]:
                    seen[l]=1
                    c+=1
        f2.write("Case #"+str(i+1)+": "+str(x)+"\n")
