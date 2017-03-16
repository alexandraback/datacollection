CurrentPathIn = "input.txt"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

def getInd(a, k):
    res = 0
    n = len(a)
    for i in range(n):
        res+=a[i]*(k**(n - i-1))
    #print(a, k, res)
    return res

T = int(fr.readline())
for t1 in range(T):
    k, c, s = list(map(int, fr.readline().split()))
    res = []
    i = 0
    while (i+1)*c <= k:
        t = getInd(list(range(i*c, (i+1)*c)),k)
        res+=[t]
        i+=1
    if k%c!=0:
        if k>c:
            res+=[getInd(list(range(k-c , k)), k)]
        else:
            res+=[getInd(list(range(k))+[0]*(c-k), k)]
    if len(res)>s or k>c*s:
        res = "IMPOSSIBLE"
    else:
        res = " ".join([str(x+1) for x in res])
    print(res)
    fw.write("Case #"+str(t1+1)+": "+res+"\n")

fr.close()
fw.close()
