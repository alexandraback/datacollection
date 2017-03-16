from math import *
import re

fu=open("A-small-attempt0.in",'r')
pro=(fu)

out=''



N=int(pro.readline())


cons="['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']"
#memo={}
def prob(name,n):
    temp=0
    size=len(name)
    for i in range(size-n+1):
        for j in range(i+n,size+1):
            check=re.compile(cons+ "{%d,}"%n)
            yes=re.search(check,name[i:j])
            if yes!=None:
                temp+=1
    return temp
        


for n in range(N):
    rawr= pro.readline().split()

    name = rawr[0]
    i = int(rawr[1])


    out=out + 'Case #%d: '%(n+1) + str(prob(name,i)) + '\n'

print out

f=open('output','w')
f.write(out)
f.close()
fu.close()


