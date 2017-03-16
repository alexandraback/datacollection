CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

def rev(n):
    res = 0
    while n>0:
        res*=10
        res+=n%10
        n=n//10
    return res

T = int(fr.readline())
for t in range(T):
    n = int(fr.readline())
    res = 1
    x = 1
    while (x < n):
        if rev(x)>x and rev(x)<=n:
            res+=1
            x = rev(x)
        else:
            x+=1
            res+=1
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")
fr.close()
fw.close()
