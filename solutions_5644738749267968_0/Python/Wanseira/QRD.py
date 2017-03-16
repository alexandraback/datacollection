import math
import time
start_time = time.time()

#list of reals
import random

def quicksort(L, M): #M sorted by L ordering
    ln = len(L)
    if ln<=1:
        return [L,M]

    lessL = []
    greaterL = []
    lessM = []
    greaterM = []

    r = random.randint(0,ln-1)
    t = L[r]

    for i in range(ln):

        s = L[i]
        if s<=t:
            lessL.append(s)
            lessM.append(M[i])
        else:
            greaterL.append(s)
            greaterM.append(M[i])

    x = quicksort(lessL,lessM)
    y = quicksort(greaterL,greaterM)
    return [x[0]+y[0],
            x[1]+y[1]]

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    Num = int(f.readline())
    A = f.readline()
    B = f.readline()
    A = A.split()
    B = B.split()
    
    for j in range(Num):
        A[j] = float(A[j])
        B[j] = float(B[j])
            
    Bricks = A+B

    order = ['A']*Num + ['B']*Num

    #do quicksort
    c = quicksort(Bricks, order)
    d = c[1] #the ordering small to big

    maxA = 0
    maxB = 0
    a = 0
    b = 0

    

    for j in range(Num*2):
        if d[j] == "A":
            a+=1
            b-=1
        else:
            a-=1
            b+=1

        if a>maxA:
            maxA=a

        if b>maxB:
            maxB=b

    
    deceitwar = Num - maxA #B is guaranteed to win max A
    war = maxB #A is guaranteed maxB
    

        
        

    g.write("Case #{}: {} {}\n".format(i+1,deceitwar,war))
    
f.close()
g.close()

print (time.time() - start_time, "secs")
