import sys

Cmb={}
Cmb[0]=[1]
Cmb[1]=[1,1]

def CombNenC(n,k):
    global Cmb
    if k==0:
        return 1
    if n==k:
        return 1
    if n==0:
        return 0
    if n in Cmb:
        return Cmb[n][k]
    nn=n
    while nn not in Cmb:
        nn-=1
    while nn<n:
        nn+=1
        Cmb[nn]=[1]
        for kk in range(1,nn):
            Cmb[nn].append(Cmb[nn-1][kk-1]+Cmb[nn-1][kk])
        Cmb[nn].append(1)
    return Cmb[n][k]

def cuenta(L,R,maxlado):
    if L>R:
        return cuenta(R,L,maxlado)
    if R==maxlado:
        # contar de cuantas formas se llena el lado derecho
        result=0
        for put in range(0,L+1):
            result+=CombNenC(R-1+put,put)
        return result
    return CombNenC(L+R,L)
      
def Diamonds(fname,sname):
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [N,X,Y]=[int(i) for i in file.readline().split()]
                H = int((((1+8*N)**0.5)-1.0)/2.0)
                while (H*(H+1)<2*N):
                    H+=1
                while (H*(H+1)>2*N):
                    H-=1
                if (H%2)==0:
                    H-=1
                result=0.0
                # ver si cae en la region completa
                if (abs(X)+abs(Y))<=H:
                    result=1.0
                # ver si cae en el siguiente nivel
                #print("Case {0}: H={1}, sobran={2}, necesita={3}\n".format(case,H,N-((H*(H+1))//2),Y+1))
                if (abs(X)+abs(Y))==(H+1):
                    necesita=Y+1
                    sobran=N-((H*(H+1))//2)
                    if sobran>=necesita:
                        # se puede cubrir
                        maxlado=H+1
                        minbuenas=max(0,sobran-maxlado)
                        maxbuenas=min(maxlado,sobran)
                        posibles=0
                        buenas=0
                        for b in range(0,sobran+1):
                            if b>maxlado:
                                continue
                            if (sobran-b)>maxlado:
                                continue
                            actual=cuenta(b,sobran-b,maxlado)
                            posibles+=actual
                            if b>=necesita:
                                buenas+=actual
                        result=buenas/posibles
                        #print("{0}/{1}\n".format(buenas,posibles))
                salida.write("Case #{0}: {1}\n".format(case,result))
        salida.close()
    file.close()

def cuentachafa(N,L,R,maxlado,necesita):
    if N==0 and L>=necesita:
        return [1,1]
    if N==0:
        return [0,1]
    if L==maxlado:
        return cuentachafa(0,L,R+N,maxlado,necesita)
    if R==maxlado:
        return cuentachafa(0,L+N,R,maxlado,necesita)
    izq = cuentachafa(N-1,L+1,R,maxlado,necesita)
    der = cuentachafa(N-1,L,R+1,maxlado,necesita)
    return [izq[0]+der[0],izq[1]+der[1]]

def DiamondsChafa(fname,sname):
    with open(fname) as file:
        with open(sname,'w') as salida:
            line = file.readline()
            T=int(line)
            for case in range(1,T+1):
                [N,X,Y]=[int(i) for i in file.readline().split()]
                H = int((((1+8*N)**0.5)-1.0)/2.0)
                while (H*(H+1)<2*N):
                    H+=1
                while (H*(H+1)>2*N):
                    H-=1
                if (H%2)==0:
                    H-=1
                result=0.0
                # ver si cae en la region completa
                if (abs(X)+abs(Y))<=H:
                    result=1.0
                # ver si cae en el siguiente nivel
                #print("Case {0}: H={1}, sobran={2}, necesita={3}\n".format(case,H,N-((H*(H+1))//2),Y+1))
                if (abs(X)+abs(Y))==(H+1):
                    necesita=Y+1
                    sobran=N-((H*(H+1))//2)
                    if sobran>=necesita:
                        # se puede cubrir
                        maxlado=H+1
                        minbuenas=max(0,sobran-maxlado)
                        maxbuenas=min(maxlado,sobran)
                        [buenas,posibles] = cuentachafa(sobran,0,0,maxlado,necesita)
                        result=buenas/posibles
                        #print("{0}/{1}\n".format(buenas,posibles))
                salida.write("Case #{0}: {1}\n".format(case,result))
        salida.close()
    file.close()
