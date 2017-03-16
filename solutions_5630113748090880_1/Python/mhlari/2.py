from collections import Counter
file = open('B-large.in.txt','r')
file_out = open('out1.txt','w')
file = file.readlines()
n = int(file[0])
it = 0
for j in range(1,n+1):
    it+=1
    N = int(file[it].strip()) 
    soldiers=[]
    for k in range(it+1, it+1+2*N-1):
        line = file[k].strip().split(' ')
        soldiers+=line
    C = Counter(soldiers)
    lost=[int(i) for i in C if C[i]%2!=0]
    list.sort(lost)    
    it +=2*N-1
    S=''
    for i in lost:
        S+= ' %i'%i 
    file_out.write('Case #%i:%s\n'%(j,S))