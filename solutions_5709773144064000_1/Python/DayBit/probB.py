'''
Created on 12/04/2014

@author: david
'''

fIn=open("B-large.in")

T=int(fIn.readline())
P=[]
for i in range(T):
    c,f,x = [float(x) for x in fIn.readline().strip().split()]

    P.append((c,f,x))
   
fRes = open("res.txt", "w") 
case = 0
for c,f,x in P:
    case += 1
    cps=2.0
    timetobuy = c/cps
    bestTime = x/cps
    acc = 0
    while True:
        cps+=f
        acc += timetobuy
        if bestTime < acc + x/cps:
            print("Case #{0}: {1:0.7f}".format(case,bestTime))
            fRes.write("Case #{0}: {1:0.7f}\n".format(case,bestTime))
            break
        timetobuy = c/cps
        
        bestTime = acc + x/cps
fRes.close()
