import math
import time
start_time = time.time()

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    p = f.readline()
    q = p.split()
    
    C = float(q[0])
    F = float(q[1])
    X = float(q[2])

    
    d = X/C - 2/F
    n = int(d)

    if n<0:
        n=0

    total = 0

    for j in range(n):
        total += C/(2+j*F)

    total += X/(2+n*F)
        
        

    s = total

    g.write("Case #{}: {}\n".format(i+1,s))
    
f.close()
g.close()

print (time.time() - start_time, "secs")
