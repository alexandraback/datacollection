import sys
import os
import math

Quats = {'1':1,'i':2,'j':3,'k':4}
one = 1
i = 2
j = 3
k = 4

MultTable = [[[1,1],[i,1],[j,1],[k,1]],[[i,1],[1,-1],[k,1],[j,-1]],[[j,1],[k,-1],[1,-1],[i,1]],[[k,1],[j,1],[i,-1],[1,-1]]]

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

def solve():
    minus = 0
    L,X = In.readline().rstrip('\n').split(' ')
    L = int(L)
    X = int(X)
    characters = list(In.readline().rstrip('\n'))
    if L == 1 or X%4 == 0:
        print('Trivially No')
        return 'NO'
    for x in range(len(characters)):
        characters[x] = [Quats[characters[x]],1]
              
    overall = characters[0]
    ipoints = []
    ijpoints = []
    ProductWorks = 0
    if overall == [2,1]:
        ipoints.append(0)
    for x in range(1,min(8,X)*L):
        overall = Multiply(overall,characters[x%L])
        if len(ipoints)==0 and overall == [2,1]:
            ipoints.append(x)
        if len(ijpoints)==0 and overall == [4,1] and len(ipoints)==1:
            ijpoints.append(x)
        print(overall)
        if x == L-1:
            if Exponentiate(overall,X) != [1,-1]:
                print(overall,'ProductDontWork',X)
                return 'NO'
            else:
                ProductWorks = 1
        if len(ipoints)==1 and len(ijpoints)==1 and ProductWorks == 1:
            return 'YES'
    return 'NO'
                
            
    
    
def Multiply(quat1,quat2):
#Multiplies two quaternions.
    return [MultTable[quat1[0]-1][quat2[0]-1][0],quat1[1]*quat2[1]*MultTable[quat1[0]-1][quat2[0]-1][1]]
    
def Exponentiate(quat,power):
    if quat[0] == 1:
        return [1, quat[1]**power]
    if quat[0] == -1:
        return [(-1)**power,quat[1]**power]
    result = [1,1]
    if power%4 == 1:
        result[0] = quat[0]
        result[1] = quat[1]
    if power%4 == 2:
        result[1] = -1      
    if power%4 == 3:
        result[0] = quat[0]
        result[1] = quat[1]
    return result
    
    
        

if __name__ == '__main__':
    T = int(In.readline())
    for x in range(T):
        print('CAAAASEEEEE ', x+1)
        Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
