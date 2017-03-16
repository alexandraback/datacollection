CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

#by i or j or k from the right
def mul(a,b):
    if b == "i":
        if a == "1":
            return "i"
        if a == "i":
            return "-1"
        if a == "j":
            return "-k"
        if a == "k":
            return "j"
        if a == "-1":
            return "-i"
        if a == "-i":
            return "1"
        if a == "-j":
            return "k"
        if a == "-k":
            return "-j"
    if b == "j":
        if a == "1":
            return "j"
        if a == "i":
            return "k"
        if a == "j":
            return "-1"
        if a == "k":
            return "-i"
        if a == "-1":
            return "-j"
        if a == "-i":
            return "-k"
        if a == "-j":
            return "1"
        if a == "-k":
            return "i"
    if b == "k":
        if a == "1":
            return "k"
        if a == "i":
            return "-j"
        if a == "j":
            return "i"
        if a == "k":
            return "-1"
        if a == "-1":
            return "-k"
        if a == "-i":
            return "j"
        if a == "-j":
            return "-i"
        if a == "-k":
            return "1"

T = int(fr.readline())
for t in range(T):
    L, X = fr.readline().split()
    L = int(L)
    X = int(X)
    S = fr.readline()
    res = 0
    if L*X < 3:
        res = "NO"
    else:
        prod = "1"
        for i in range(L):
            prod = mul(prod,S[i])
        #All product is -1
        if (X%2==1 and prod == "-1") or (X%4==2 and prod!="1" and prod!="-1"):
            #find first i:
            p = "1"
            f= 0
            cur = 0
            for i in range(min(4,X)*L):
                p = mul(p,S[i%L])
       #         print(S[i%L])
                if p=="i":
                        f = 1
                        cur = i
                        break
            if f==1:
                #find first j:
                p = "1"
                f= 0
                for i in range(cur+1, min(cur + 1 + L*min(4,X), L*X)):
                    p = mul(p,S[i%L])
                    if p=="j":
                        f = 1
                        break
                if f == 1:
                    res = "YES"
                else:
                    res = "NO"      
            else:
                res = "NO"
        else:
            res = "NO"
    print(res)
    fw.write("Case #"+str(t+1)+": "+res+"\n")

fr.close()
fw.close()
