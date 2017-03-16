import sys
import os
import math

In = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[1])
Out = open(os.path.dirname(os.path.abspath(__file__))+'/'+sys.argv[2],'w')

def solve():
    D = int(In.readline())
    if D == 0:
        return 0
    List = In.readline().rstrip('\n').split(' ')
    List = [int(List[i]) for i in range(len(List))]
    List.sort()
    print(List)
    return min([find_min(List, i) for i in range(List[-1])])
    
    
def find_min(L, specials):
#Recursively finds the minimum of the infinite pancake house problem. Input is a sorted list and a number of special minutes to take.
#This uses the observation that a minimum for one stack of height k is achieved dividing into ceil(sqrt(k)) stacks.
#Output minimal number of minutes needed
    if specials == 0:
        return L[-1]
    if L[-1] == 0:
        return  0
    if L[-1] ==1:
        return 1
    if len(L) == 1 and specials < math.ceil(math.sqrt(L[-1])):
        return math.ceil(L[-1]/specials)+specials-1
    if len(L) == 1 and specials >= math.ceil(math.sqrt(L[-1])):
        return math.ceil(L[-1]/math.ceil(math.sqrt(L[-1])))+math.ceil(math.sqrt(L[-1]))-1
    if specials >= math.ceil(math.sqrt(L[-1])) and math.ceil(L[-1]/math.ceil(math.sqrt(L[-1]))) >= L[-2]:
        return math.ceil(L[-1]/math.ceil(math.sqrt(L[-1]))) + math.ceil(math.sqrt(L[-1])) - 1
        
    for k in range(1, math.ceil(math.sqrt(L[-1]))):
        print(k,specials)
        #Finds the k such that dividing into math.ceil(math.sqrt(L[-1]))-k stacks is still above L[-2]. We should at least divide k into so many stacks. max is the maximum number of minutes it will take now.
        if math.ceil(math.sqrt(L[-1]))-k-1 > specials:
            continue
        if math.ceil(L[-1]/(math.ceil(math.sqrt(L[-1]))-k)) >= L[-2]:
            minstacknumber = math.ceil(math.sqrt(L[-1]))-k
            maximum = max(L[-2],math.ceil(L[-1]/(math.ceil(math.sqrt(L[-1]))-k)))+math.ceil(math.sqrt(L[-1]))-k-1
            break
    for k in range(minstacknumber+1,max(math.ceil(math.sqrt(L[-1]))+1,specials+1)):
    #We divide the largest stack into k stack now. This takes k-1 minutes.
        if specials -k+1<0:
            continue
        rest = find_min(L[0:-1], specials -k+1)
        if maximum > max(rest, math.ceil(L[-1]/k)) + k-1:
            maximum = max(rest, math.ceil(L[-1]/k)) + k-1
    
    return maximum
        
        
    
        

if __name__ == '__main__':

    T = int(In.readline())
    for x in range(T):
        Out.write('Case #{}: {}\n'.format(x+1,solve()))
            
 
                

                    
                  
            
