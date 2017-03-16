file = open('B-small-attempt0.in', 'r')
file2 = open('B-small-attempt0.out', 'w')

n=int(file.readline())

def invert(d,a):
    t=a[0:d]
    for i in range(d):
        if t[d-1-i]=="-":
            a[i]="+"
        else:
            a[i]="-"
for i in range(n):
    a=[i for i in (file.readline())][0:-1]
    nb=0
    l=len(a)
    f=l
    d=0

    while f!=0 and a[f-1]=="+":
        f-=1





    while f>0:
        d=0
        while d<l and a[d]=="+":
            d+=1


        if d:
            invert(d,a)
            nb+=1

        d=0
        while d<l and a[d]=="-":
            d+=1
        invert(f,a)
        f-=d

        nb+=1


    file2.write("Case #"+str(i+1)+": "+str(nb)+"\n")
