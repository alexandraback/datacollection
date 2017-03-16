import math
f = open("A-small-attempt0.in","r")
o = open("A-small-answers.txt","w")
T = int(f.readline())
for t in range(1,T+1):
    inp = [float(a) for a in f.readline().split("/")]
    p = inp[0]
    q = inp[1]
    print(p,"/",q)
    b = int(math.log(q,2))
    print(b)
    p = p/(q/(2**b))
    print(p)
    a = int(math.log(p,2))
    if p%1 != 0:
        o.write("Case #"+str(t)+": impossible"+"\n")
    else:
        o.write("Case #"+str(t)+": "+str(b-a)+"\n")
    
o.close()
#o.write("Case #"+str(t)+": NOT POSSIBLE"+"\n")
#A-small-attempt0.in
