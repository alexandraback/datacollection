def findMax(num , e, r,curE, act,tt):
    maximum = 0
    
    for x in range(int(curE)+1):
        eGain = int(r)
        newE = int(curE) - x + eGain
        if newE > int(e):
            newE = e
        
        if int(tt) + 1 < int(num):
            cur = x * int(act[tt]) + findMax(num,e,r,newE,act,tt+1)
            if int(cur) > int(maximum):
                maximum = cur
        else:
            return int(curE)*int(act[tt])

    return int(maximum)
            
            
            
        
f = open("DATA1.txt")
g = open("OUT1.txt",'w')
n = f.readline().strip()
for x in range(int(n)):
    a = f.readline().strip().split(" ")
    e = a[0]
    r = a[1]

    act = f.readline().strip().split(" ")
    curE = e
    y = findMax(a[2],e,r,curE,act,0)
    g.write("Case #"+str(int(x+1))+": "+str(y)+"\n")
g.close()
