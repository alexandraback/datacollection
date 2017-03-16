from math import ceil

file = open('D-large.in', 'r')
file2 = open('D-large.out', 'w')

n=int(file.readline())


for i in range(n):
    k,c,s=[int(i) for i in (file.readline().split())]
    nb=ceil(k/c)

    if nb>s:
        file2.write("Case #"+str(i+1)+": IMPOSSIBLE\n")
    else:
        file2.write("Case #"+str(i+1)+":")
        #print("c",i,k,c,s,nb)


        x=0
        count=0
        g=0
        while count<k or g:
            if count<k:
                x*=k
                x+=count
            g+=1
            count+=1
            #print(x,count,g)
            if g==c:
                file2.write(" "+str(x+1))
                x=0
                g=0

        #print(x,count,g)
        file2.write("\n")
