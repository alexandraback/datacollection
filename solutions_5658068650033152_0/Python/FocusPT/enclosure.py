#__author__ = 'afonso-ferreira'
from math import sqrt, ceil
file = open('enclosure_small.in', 'r')
matrix=file.read().split('\n')

for aux in range(1, int(matrix[0])+1):
    n=matrix[aux].split(' ')
    size=[0,0]
    size[0]=int(n[0])
    size[1]=int(n[1])
    n=int(n[2])+4
    number=ceil(sqrt(n))
    tag=0
    if(n-4<8):
        res=n;
    else:
        while(1):
            if(n%number==0):
                n2=int(n/number)
                if(n2<=size[0] and n2<=size[1]):
                    break
            number=number+1
        res=2*(number-2)+2*(n2-2)

    print('Case #',end="")
    print(aux,end="")
    print(":",end=" ")
    print(res)