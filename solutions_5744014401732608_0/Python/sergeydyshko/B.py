CurrentPathIn = "input"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

T = int(fr.readline())

for t in range(T):
    b, m = list(map(int, fr.readline().split()))
    M = [[0]*b for i in range(b)]
    for i in range(b-1):
        M[i][i+1] = 1
    a = bin(m)
    a = a[2:]
    a = [int(x) for x in a]
    if 2**(b-2) < m:
        fw.write("Case #"+str(t+1)+": "+str("IMPOSSIBLE")+"\n")
    else:
        for i in range(b - len(a) -3, b):
            for j in range(i+1, b):
                M[i][j]=1
        if len(a)-1 != b-2:
            for i in range(1,len(a)):
                if a[i]==1:
                    M[b - len(a) - 4][ b - len(a) - 3 + i ] = 1
        fw.write("Case #"+str(t+1)+": "+str("POSSIBLE")+"\n")
        for i in range(b):
            fw.write("".join([str(x) for x in M[i]])+"\n")
fr.close()
fw.close()
