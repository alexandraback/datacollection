from itertools import product as product


def solve(C,J,QC,QJ):

    Cp = C[::]
    
    Jp = J[::]
    minC,minJ = 0,0
    
    mind,minc,minj = 1e9,1e9,1e9
    
    if len(QC) == 0:
        for y in product('0123456789',repeat = len(QJ)):

            for qj in range(len(QJ)):
                Jp[QJ[qj]] = y[qj]

            c,j = int(''.join(i for i in Cp)),int(''.join(i for i in Jp))
            dist = abs(c-j)

            
            if dist < mind:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist
            elif dist == mind and c < minc:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist
                
            elif dist == mind and c == minc and j < minj:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist


    elif len(QJ) == 0:
        for x in product('0123456789',repeat = len(QC)):
            for qc in range(len(QC)):
                Cp[QC[qc]] = x[qc]


            c,j = int(''.join(i for i in Cp)),int(''.join(i for i in Jp))
            dist = abs(c-j)

            
            if dist < mind:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist
            elif dist == mind and c < minc:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist
                
            elif dist == mind and c == minc and j < minj:
                mind = dist
                minc = c
                minj = j
                
                minC,minJ = Cp[::],Jp[::]
                #print c,j,dist

    else:
        for x in product('0123456789',repeat = len(QC)):
            for y in product('0123456789',repeat = len(QJ)):
                for qc in range(len(QC)):
                    Cp[QC[qc]] = x[qc]

                for qj in range(len(QJ)):
                    Jp[QJ[qj]] = y[qj]

                c,j = int(''.join(i for i in Cp)),int(''.join(i for i in Jp))
                dist = abs(c-j)

                
                if dist < mind:
                    mind = dist
                    minc = c
                    minj = j
                    
                    minC,minJ = Cp[::],Jp[::]
                    #print c,j,dist
                elif dist == mind and c < minc:
                    mind = dist
                    minc = c
                    minj = j
                    
                    minC,minJ = Cp[::],Jp[::]
                    #print c,j,dist
                    
                elif dist == mind and c == minc and j < minj:
                    mind = dist
                    minc = c
                    minj = j
                    
                    minC,minJ = Cp[::],Jp[::]
                    #print c,j,dist


    return minC,minJ
            
                     

    


    

F = open('B-small-attempt0.in')
O = open('B-small-attempt0.out','w')

#F = open('B-large-practice.in')
#O = open('B-large-practice.out','w')


T = int(F.readline())

print T


for case in range(1,T+1):
    C,J = F.readline().strip().split()
    print case


    QC = []
    QJ = []
    for i in range(len(C)):
        if C[i] == '?':
            QC.append(i)

    for i in range(len(J)):
        if J[i] == '?':
            QJ.append(i)
            

    C = list(i for i in C)
    J = list(i for i in J)
    
    ans = solve(C,J,QC,QJ)
            

    

    #print ans

    O.write('Case #%d: %s %s\n'%(case,''.join(i for i in ans[0]),''.join(i for i in ans[1])))
        
        
                
                
        



F.close()
O.close()
    
        
