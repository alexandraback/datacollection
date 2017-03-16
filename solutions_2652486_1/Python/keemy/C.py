from math import *
prob=(open('C-small-2-attempt0.in','r'))
out=''


def factor(n):  
    fact=[1,n]  
    check=2  
    rootn=sqrt(n)  
    while check<rootn:  
        if n%check==0:  
            fact.append(check)  
            fact.append(n/check)  
        check+=1  
    if rootn==check:  
        fact.append(check)  
        fact.sort()  
    return fact  
    


def find_nums( k_list, N, M):
    output=[]
    factors=set()
    for i in range(len(k_list)):
        factors= factors | set(factor(k_list[i]))

    if 3 in factors:
        output.append(3)
        if 9 in factors:
            output.append(3)
            if 27 in factors:
                output.append(3)
                
    if 5 in factors:
        output.append(5)
        if 25 in factors:
            output.append(5)
            if 125 in factors:
                output.append(5)

    tempp= N-len(output)
    i=1
    while i*2 in factors:
        i*=2
    
    if i== 64:
        output.append(4)
        output.append(4)
        output.append(4)
    if i== 32:
        output.append(2)
        output.append(4)
        output.append(4)
    if i== 16:
        if tempp==2:
            output.append(4)
            output.append(4)
        else:
            output.append(4)
            output.append(2)
            output.append(2)
    if i==8:
        if tempp==2:
            output.append(4)
            output.append(2)
        if tempp==3:
            output.append(2)
            output.append(2)
            output.append(2)
    if i==4:
        if tempp==1:
            output.append(4)
        if tempp==2:
            output.append(2)
            output.append(2)
        if tempp==3:
            output.append(2)
            output.append(2)
            output.append(2)


    while N>len(output):
        output.append(2)


    m=""
    for i in output:
        m+=str(i)
        
    return m

prob.readline()
arrr=prob.readline().split()
T=int(arrr[0])
N=int(arrr[1])
M=int(arrr[2])


out='Case #1:\n'
for n in range(T):
    arrr=prob.readline().split()
    k_list=[int(a) for a in arrr]
    
    out=out + find_nums(k_list, N,M) + '\n'

print out

f=open('output','w')
f.write(out)
f.close()


