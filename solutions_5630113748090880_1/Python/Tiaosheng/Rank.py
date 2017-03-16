file = open('B-large.in', 'r')
file2 = open('B-large.out', 'w')

n=int(file.readline())

for i in range(n):

    m=int(file.readline())
    tab=[]
    for j in range(2*m-1):
        tab+=[int(i) for i in file.readline().split()]

    tab.sort()
    l=[]
    last=tab[0]-1
    nb=0
    for x in tab:
        if x==last:
            nb+=1
        else:
            if nb%2:
                l+=[last]
            last=x
            nb=1
    if nb%2:
        l+=[last]
    last=x
    nb=1

    file2.write("Case #"+str(i+1)+":")
    for x in l:
        file2.write(" "+str(x))
    file2.write("\n")
