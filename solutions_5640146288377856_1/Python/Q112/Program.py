import sys
import os
from math import*

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')


def solve():
    R, C, W = In.readline().split(' ')
    R, C, W = int(R), int(C), int(W)
    if C%W:
        return R * int(C/W) + W
    else:
        return R * (floor(C/W)) + W - 1

        

if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
            Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
