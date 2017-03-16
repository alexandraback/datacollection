# Google code jam
import numpy as np

# read number of cases from stdin    
T = int(input())

for t in range(1,T+1):

    S = input().split(' ') # read number of senators
    B = int(S[0])
    M = int(S[1])

    Sol = np.zeros((B,B),dtype=int)
    
    for i in range(B,1,-1):
        for j in range(i,0,-1):
            Sol[0,j-1] = 1
            if j < B:
                Sol[j-1,i-1] = 1
            M -= 1
            if M == 0:
                break
        if M == 0:
            break

    if M > 0:
        print("Case #{}: {}".format(t,'IMPOSSIBLE'))
    else:
        print("Case #{}: {}".format(t,'POSSIBLE'))
        for i in range(0,B):
            line = ''
            for j in range(0,B):
                line += str(Sol[i,j])
            print(line)
