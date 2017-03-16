import sys

memoria={}
E=0
R=0
V=[]
N=0

def busca(index,current):
    if index==N:
        return 0
    if index not in memoria:
        memoria[index]={}
    if current in memoria[index]:
        return memoria[index][current]
    mejor=0
    for e in range(0,current+1):
        opcion=e*V[index]+busca(index+1,min(E,current-e+R))
        if opcion>mejor:
            mejor=opcion
    memoria[index][current]=mejor
    return mejor
        

def Manage(fname,sname):
    global memoria,E,R,V,N
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [E,R,N]=[int(i) for i in file.readline().split()]
                V = [int(i) for i in file.readline().split()]
                memoria={}
                salida.write("Case #{0}: {1}\n".format(case,busca(0,E)))
        salida.close()
    file.close()
