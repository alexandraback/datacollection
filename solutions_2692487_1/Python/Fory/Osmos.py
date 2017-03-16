import sys

M=[]

def busca(A,index):
    global M
    if index>=len(M):
        return 0
    if M[index]<A:
        return busca(A+M[index],index+1)
    #no comer
    mejor=len(M)-index
    if (A>1):
        actual=1+busca(A+A-1,index)
        if actual<mejor:
            return actual
    return mejor

def Osmos(fname,sname):
    global M
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [A,N]=[int(i) for i in file.readline().split()]
                M = [int(i) for i in file.readline().split()]
                M.sort()
                salida.write("Case #{0}: {1}\n".format(case,busca(A,0)))
        salida.close()
    file.close()
