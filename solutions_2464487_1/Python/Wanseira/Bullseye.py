import math
import time
start_time = time.time()

f=open("A.in",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    p = f.readline()
    p = p.split()

    r = int(p[0])
    t = int(p[1])
##
##    x = (2*r-1)**2
##
##    x += 8*t
##
##    x = math.sqrt(x)
##
##    x -= (2*r-1)
##
##    x /= 4


    x = 4*t/(2*r-1)
    a = -1

    while math.fabs(x-a)>0.5:
        a = 2*(x**2) + (2*r-1)*x - t
        a /= 4*x + (2*r-1)
        a *= -1
        a += x


        b = x
        x = a
        a = b


    k = math.floor(x)
    if k*(2*r-1+2*k)>t:
        x = k-1
    else:
        x = k
    
    
    x = int(x)


    g.write("Case #{}: {}\n".format(i+1,x))

    if i%1000==0:
        print(i)



    
f.close()
g.close()

print (time.time() - start_time, "secs")
