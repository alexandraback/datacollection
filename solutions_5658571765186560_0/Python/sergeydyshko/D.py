CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())
for t in range(T):
    X, R, C = list(map(int,fr.readline().split()))
    res = 0
    if (R*C) % X != 0:
        res = "RICHARD"
    else:
        if X == 1:
            res = "GABRIEL"
        elif X==2:
            if R%2==1 and C%2==1:
                res = "RICHARD"
            else:
                res = "GABRIEL"
        elif X==3:
            if R==1 or C == 1:
                res = "RICHARD"
            else:
                res = "GABRIEL"
        elif X==4:
            if R==2 or C==2 or R == 1 or C==1:
                res = "RICHARD"
            else:
                res = "GABRIEL"
    print(res)
    fw.write("Case #"+str(t+1)+": "+res+"\n")
fr.close()
fw.close()
