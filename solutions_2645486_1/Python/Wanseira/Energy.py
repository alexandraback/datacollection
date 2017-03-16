import math
import time
start_time = time.time()

f=open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    p = f.readline()
    q = f.readline()
    p = p.split()
    q = q.split()

    E = int(p[0])
    R = min(E,int(p[1]))
    N = int(p[2])

    matters = math.ceil(E/R)-1

    s = 0
    energy = E

    for j in range(N):
        x = int(q[j])

        k = j+1

        stop = 0
        while k<N and k<= j+matters:
            if int(q[k])>x:
                stop = 1
                break
            k+=1


        if stop==0:
            s += energy*x
            energy = R #(0+R)
            
        if stop == 1:
            lamb = E - R* (k-j)


            if energy<=lamb: #rest
                energy += R
            else:
                s += x*(energy-lamb)
                energy = lamb + R

    g.write("Case #{}: {}\n".format(i+1,s))

    if i%1000000==-1:
        print(i)
                
        





    
f.close()
g.close()

print (time.time() - start_time, "secs")
