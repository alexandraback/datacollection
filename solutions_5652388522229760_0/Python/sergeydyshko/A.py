CurrentPathIn = "small.in"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")  

def foo(n):
    if n==0:
        return "INSOMNIA"
    arr = {}
    t = 0
    while len(arr)<10:
        t += n
        s = str(t)
        for c in s:
            if c not in arr:
                arr[c]=1
    return str(t)
        

T = int(fr.readline())
for t in range(T):
    n = int(fr.readline())
    res = foo(n)
    #print(res)
    fw.write("Case #"+str(t+1)+": "+res+"\n")

fr.close()
fw.close()
