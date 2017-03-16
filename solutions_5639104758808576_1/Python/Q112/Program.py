import sys
import os

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')


def solve():
    Smax, Sindividual = In.readline().rstrip('\n').split(' ')
    Smax = int(Smax)
    S = [int(Sindividual[i]) for i in range(len(Sindividual))]
    Standing = 0
    Friends = 0
    
    for k in range(Smax+1):
        if k > Standing:
            Friends += k - Standing
            Standing = k
        Standing += S[k]
            
    return Friends
        

if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
            Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
