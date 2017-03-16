CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())
for tk in range(T):
    n = int(fr.readline())
    res = 0
    if n==1:
        d, h, m = list(map(int,fr.readline().split()))
        res = 0
    else:
        d1, h1, s1 = list(map(int,fr.readline().split()))
        d2, h2, s2 = list(map(int,fr.readline().split()))
        s1 = 360/s1
        s2 = 360/s2
        if s1 == s2:
            res = 0
        else:
            t = (d1 - d2)/(s1 - s2)
            if t <= 0:
                t+= (360/abs(s1 - s2))
            t1 = (360 - d1)/s1
            t2 = (360 - d2)/s2
            tm = max(t1,t2)
            if tm >= t and min(t1,t2) < t:
                res = 1
            else:
                res = 0
            print(t1,t2,t)
    fw.write("Case #"+str(tk+1)+": "+str(res)+"\n")
fr.close()
fw.close()
