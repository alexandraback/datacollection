CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

def mintime(P):
    if len(P)>0:
        res = []
        if max(P)>1:
                    m=max(P)
                    Pdiv = [x for x in P] 
                    Pdiv.remove(m)
                    Pdiv.append(m//2)
                    Pdiv.append(m - m//2)
                    res.append(mintime(Pdiv))
                    res.append(mintime([x-1 for x in P if x>1]))
                    return min(res)+1
        else:
            return 1
    else:
        return 0

T = int(fr.readline())
for cnt in range(T):
    print(cnt)
    D = int(fr.readline())
    P = list(map(int,fr.readline().split()))
    res= mintime(P)
    #print(res)
    fw.write("Case #"+str(cnt+1)+": "+str(res)+"\n")
fr.close()
fw.close()
