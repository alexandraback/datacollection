CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())
for t in range(T):
    n, S = fr.readline().split()
    n = int(n)

    res = 0
    alr = 0
    for i in range(n+1):
        x = int(S[i])
        if i > alr:
            res += i - alr
            alr = i
        alr+=x
    #print(res)
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")
fr.close()
fw.close()
