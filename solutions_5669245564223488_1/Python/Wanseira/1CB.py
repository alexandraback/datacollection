import math
import time
from fractions import gcd

AA = 1000000007

start_time = time.time()

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

def intersection(a,b):
    return [val for val in a if val in b]
def valid(text): #no contradictions
    for i in range(26):
        c = chr(97+i)
        l = [i for i,x in enumerate(text) if x==c]

        ln = len(l)
        if ln>=1:
            t = l[0]
            for j in range(ln):
                if l[j]!=t+j:
                    return 0
    return 1

def join(cars, rev): #return end and number of independent parts
    ln = len(cars)

    if ln ==0:
        return [1,0]

    for i in range(ln):
        if valid(cars[i])==0:
            return [0,0]
    #validity check

    
    t = cars[0][-1]

    s=[]

    for i in range(ln):
        if i!=0 and t in cars[i]:
            s.append(i)

    if len(s)==0: # independent?
        ind = 1
        for i in range(ln):
            if i!=0 and len(intersection(cars[0],cars[i]))!=0:
                ind = 0
                break
        if ind == 1:
            ans = join(cars[1:],0)
            ans[1]+=1
            return ans
        else:
            if rev ==1:
                return 0 #impossible
            else:
                for i in range(ln):
                    cars[i] = cars[i][::-1] #reverse
                return join(cars,1) #not good  enough
        
    #so stuff to join on end? see s
    start = -1
    for i in s:
        if cars[i][0]!=t:
            start = i

    if start!=-1:
        if cars[0][0] !=t:
            return [0,0]
        else:
            g = cars[0]
            cars[0] = cars[start]
            cars[start] = g

            return join(cars,0)




    u = len(s)
    #plenty to sort out
    end = -1
    for i in s:
        if cars[i][-1]!=t:
            end = i
            break

    if end == -1:
        for i in s:
            cars[0]+=cars[i]

        i=1
        while i<len(cars):
            
            if t in cars[i]:
                del cars[i]
                i=i-1
            i=i+1
        ans = join(cars[:],0)

        for i in range(u):
            ans[0] = (ans[0]*(i+1) )%AA #combos
        if cars[0][0]==t:
            
            ans[0] = (ans[0]*(u+1)) %AA
        return ans
    else:
        speccar = cars[end]
        cars[end] = ''

        for i in s:
            
            cars[0]+=cars[i]

        cars[0] += speccar

        i=1
        while i<len(cars):
            
            if t in cars[i] or cars[i]=='':
                del cars[i]
                i=i-1
            i=i+1
        ans = join(cars[:],0)

        for i in range(u-1):
            ans[0] = (ans[0]*(i+1) )%AA #combos
        if cars[0][0]==t:
            ans[0] = ans[0]*(u) %AA

        return ans

            
    

    return s
    
    

for j in range(ntests):
    p = f.readline()
    N = int(p) #N

    p = f.readline()
    cars = p.split()
    
    
    s=join(cars,0)

    t = s[1]

    for i in range(t):
        s[0] = (s[0]*(i+1)) %AA

    

    g.write("Case #{}: {}\n".format(j+1,s[0]))
    
f.close()
g.close()

print (time.time() - start_time, "secs")
