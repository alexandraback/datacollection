import sys
import os
import math

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

def solve():
    X, R, C = map(int,In.readline().rstrip('\n').split(' '))
    
    R, C = min(R,C), max(R,C)

    if X > 6:
        return 'RICHARD'
    if (R*C)%X != 0:
        return 'RICHARD'
    if R < math.floor(math.sqrt(X)) or C < X:
        return 'RICHARD'
    if X == 3 and R == 1:
        return 'RICHARD'
    if X < 4:
        return 'GABRIEL'
    if X == 4 and R == 2:
        return 'RICHARD'
    if X == 4 and R != 2:
        return 'GABRIEL'
        
        
    
        

if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
        Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
