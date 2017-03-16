CurrentPathIn = "input"
CurrentPathOut = "output"

import itertools

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

def match(x1, s1):
    for i in range(len(x1)):
        if s1[i]!='?' and x1[i]!=s1[i]:
            return False
    return True
    
T = int(fr.readline())
for t in range(T):
    c, j = fr.readline().rstrip("\n").split(" ")
    c = list(c)
    j = list(j)
    n = len(c)
    D = 10**20
    I1 = 10**20
    I2 = 10**20
    R1 = ""
    R2 = ""
    for a in itertools.product(list(range(10)), repeat = n):
        x1 = "".join([str(a1) for a1 in a])
        if match(x1,c):
            for b in itertools.product(list(range(10)), repeat = n):
                x2 = "".join([str(a1) for a1 in b])
                if match(x2,j):
                    i1 = int(x1)
                    i2 = int(x2)
                    d = abs(i1 - i2)
                    if d<D:
                        D = d
                        I1 = i1
                        I2 = i2
                        R1 = x1
                        R2 = x2
                    elif d==D:
                        if I1 > i1:
                            I1 = i1
                            I2 = i2
                            R1 = x1
                            R2 = x2
                        elif I1==i1:
                            if I2 > i2:
                                I2 = i2
                                R2 = x2
    print(R1, R2)
    fw.write("Case #"+str(t+1)+": "+R1+" "+R2+"\n")
fr.close()
fw.close()
