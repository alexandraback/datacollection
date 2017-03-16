CurrentPathIn = "input.txt"
CurrentPathOut = "output"

fr = open(CurrentPathIn,"r")
fw = open(CurrentPathOut,"w")

def seq(s):
    i = 0
    while i<len(s) and s[i]==s[0]:
        i+=1
    return i-1

def seqR(s):
    n = len(s)
    i = n-1
    while i>=0 and s[i]==s[n-1]:
        i-=1
    return i+1

def foo(s):
    n = len(s)
    if n==0:
        return 0
    if s[n-1]=='+':
        return foo(s[:seqR(s)])
    i = seq(s)
    if s[0]=='-':
        for j in range(i+1):
            s[j]='+'
        return 1 + foo(s)
    else:
        s = s[i+1:]
        s = list(reversed(s))
        for i in range(len(s)):
            if s[i]=='-':
                s[i]='+'
            else:
                s[i]='-'
        return 2+ foo(s)


T = int(fr.readline())
for t in range(T):
    s = list(fr.readline().rstrip("\n"))
    res = foo(s)
    #print(res)
    fw.write("Case #"+str(t+1)+": "+str(res)+"\n")

fr.close()
fw.close()
