# Sean Liu
# War

f = open("D-large.in", "r")
g = open("output.txt", "w")

T = int(f.readline())

for i in range(T):
    num = int(f.readline())

    naomi = f.readline().split()
    naomi = sorted([float(x) for x in naomi])
    
    ken = f.readline().split()
    ken = sorted([float(x) for x in ken])

    deceitful = 0
    naomitemp = naomi[:]
    kentemp = ken[:]
    pos = 0
    while len(kentemp)>pos:
        if naomitemp[pos] < kentemp[pos]:
            naomitemp.pop(pos)
            kentemp.pop(len(kentemp)-1)
        else:
            pos += 1
    deceitful = len(naomitemp)
            
    naomitemp = naomi[:]
    kentemp = ken[:]
    while len(kentemp)>0:
        if naomitemp[0] < kentemp[0]:
            naomitemp.pop(0)
            kentemp.pop(0)
        else:
            kentemp.pop(0)      
    normal = len(naomitemp)
    
    
    g.write("Case #{}: {} {}\n".format(i+1, deceitful, normal))

f.close()
g.close()
