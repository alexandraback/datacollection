import sys

memoria={}
E=0
R=0
V=[]
N=0

def Manage(fname,sname):
    global memoria,E,R,V,N
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [E,R,N]=[int(i) for i in file.readline().split()]
                V = [int(i) for i in file.readline().split()]
                i=0
                total=0
                current=E
                j=0
                while i<(N-1):
                    # search next better
                    j=i
                    while j<N and V[j]<=V[i]:
                        j+=1
                    if j==N:
                        # nada es mejor, usar todo
                        total+=current*V[i]
                        i+=1
                        current=R
                        continue
                    siguiente = (R*(j-i)+current)
                    if (siguiente<=E):
                        # no se puede usar desde este hasta j
                        i=j
                        current=siguiente
                        continue
                    extra = siguiente-E
                    if extra<=current:
                        total+=extra*V[i]
                        i+=1
                        current+=R-extra
                        continue
                    total+=current*V[i]
                    i+=1
                    current=R
                total+=current*V[i]
                salida.write("Case #{0}: {1}\n".format(case,total))
        salida.close()
    file.close()
