file = open('A-large.in', 'r')
file2 = open('A-large.out', 'w')

n=int(file.readline())

for i in range(n):
    a=[i for i in (file.readline())]


    f=[]
    d=[]

    while a:
        m=max(a)
        e=a.pop()
        while e!=m:
            f=[e]+f
            e=a.pop()
        d=d+[e]
    nb="".join(d+f)[:-1]

    file2.write("Case #"+str(i+1)+": "+str(nb)+"\n")
