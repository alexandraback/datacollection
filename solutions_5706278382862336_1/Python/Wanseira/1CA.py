import math
import time
from fractions import gcd

start_time = time.time()

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    p = f.readline()
    q = p.split('/')

    a = int(q[0])
    b = int(q[1])      
    h = gcd(a,b)

    t = int(b/h)

    j = 0
    while t%2==0:
        t/=2
        j+=1
    if t!=1:
        s = 'impossible'
    else:
        t = a/b
        j = 0
        while t<1:
            t*=2
            j+=1
        s = j
    

    g.write("Case #{}: {}\n".format(i+1,s))
    
f.close()
g.close()

print (time.time() - start_time, "secs")
