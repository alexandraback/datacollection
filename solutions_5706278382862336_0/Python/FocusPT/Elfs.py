#__author__ = 'afonso-ferreira'

file = open('elfs_small_1.in', 'r')
matrix=file.read().split('\n')

for aux in range(1, int(matrix[0])+1):
    n=matrix[aux].split('/')
    n[0]=int(n[0])
    n[1]=int(n[1])
    counter=1
    next_n=0
    total_count=0
    comp=1
    res=0
    out_k=0
    last_tag=0
    #if(n[1]%2!=0):
    #    comp=0
    #    last_tag=1
    #    print('Case #',end="")
    #    print(aux,end="")
    #    print(":",end=" ")
    #   print("impossible")

    while(comp!=0 and total_count<42):
        while(next_n != 1 and counter <41):
            if(2*n[0]-n[1] >= 0):
                comp=2*n[0]-n[1]
                n[0]=n[1]
                #print(n[0])
                next_n=1
            elif(2*n[0]<=n[1]):
                n[0]=2*n[0]
                #print(n[0])
                next_n=n[0]/n[1]
                comp=0
            else:
                print("ERROR- case not predicted")
            counter=counter+1
        total_count=total_count+counter
        n[0]=comp
        next_n=0
        if(out_k==0):
            res=counter-1
        out_k=1
        counter=0
    if total_count>40:
        print('Case #',end="")
        print(aux,end="")
        print(":",end=" ")
        print("impossible")
    elif(last_tag==0):
        print('Case #',end="")
        print(aux,end="")
        print(":",end=" ")
        print(res)