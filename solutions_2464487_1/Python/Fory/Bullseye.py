import sys

def Bullseye(fname,sname):
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [r,t]=[int(i) for i in file.readline().split()]
                k=int(((1-2*r)+((2*r-1)**2+8*t)**0.5)/4.0)
                area=0
                while area<=t:
                    k+=1
                    area=(2*r-3)*k+2*k*k+2*k
                while area>t:
                    k-=1
                    area=(2*r-3)*k+2*k*k+2*k
                salida.write("Case #{0}: {1}\n".format(case,(k)))
        salida.close()
    file.close()
