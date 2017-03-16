import math

f=open("A.in",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):
    p = f.readline()
    p = p.split()

    r = int(p[0])
    t = int(p[1])

    x = (2*r-1)**2

    x += 8*t

    x = math.sqrt(x)

    x -= (2*r-1)

    x /= 4

    x = int(x)


    g.write("Case #{}: {}\n".format(i+1,x))

    if i%200==0:
        print(i)



    
f.close()
g.close()
