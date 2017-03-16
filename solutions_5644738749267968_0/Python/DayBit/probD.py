'''
Created on 12/04/2014

@author: david
'''
fIn=open("D-small-attempt0.in")

T=int(fIn.readline())
P=[]
for i in range(T):
    nb = int(fIn.readline())
    naomi = [float(x) for x in fIn.readline().strip().split()]
    ken = [float(x) for x in fIn.readline().strip().split()]
    naomi.sort()
    ken.sort()
    P.append((naomi,ken))
  
case = 0
fRes = open("res.txt", "w")  
for naomi,ken in P:
    case += 1
    #print(naomi,ken)
    nw=0
    nw2=0
    naomi2 = naomi[:]
    ken2=ken[:]
    for _ in range(len(naomi)):
        if naomi[0]>ken[0]: #tu menor gana a su menor
            del naomi[0]
            del ken[0]
            nw += 1
        else: # no ganas a su mayor
            del naomi[0]
            del ken[-1]
    for _ in range(len(naomi2)):
        pos = 0
        for i in range(len(naomi2)):
            if ken2[i]>naomi2[0]:
                pos=i
                break
        if naomi2[0]>ken2[pos]:
            nw2 += 1
        del naomi2[0]
        del ken2[pos]   
        
    print("Case #{}: {} {}".format(case,nw,nw2)) 
    fRes.write("Case #{}: {} {}\n".format(case,nw,nw2))  
fRes.close()