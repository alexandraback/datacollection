# Google code jam
import numpy as np

# read number of cases from stdin    
T = int(input())

for j in range(1,T+1):

    JPSK = input().split(' ') # read number of senators
    J = int(JPSK[0])
    P = int(JPSK[1])
    S = int(JPSK[2])
    K = int(JPSK[3])

    idx = (np.argsort(np.array([J,P,S]))).tolist()
    JPS = np.sort(np.array([J,P,S]))
    NmaxK = JPS[0]*JPS[1]*min([JPS[2],K])
    
    print("Case #{}: {}".format(j,NmaxK))

    for j in range(1,JPS[0]+1):
        for p in range(1,JPS[1]+1):
            for s in range(1,min([JPS[2],K])+1):
                Style = [j,p,s]
                StyleStr = str(Style[idx.index(0)])
                StyleStr += (' '+str(Style[idx.index(1)]))
                StyleStr += (' '+str(Style[idx.index(2)]))
                print(StyleStr)
                
    
