f = open("QBInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    S = f.readline()
##    S = sys.stdin.readline()
    l = len(S)
    m = 0
    for p in range(1,l-1):
        if S[p] != S[p-1]:
            m = m+1
    if S[l-2] == "-":
        m = m+1
    n = n+"Case #"+str(i+1)+": "+str(m)+"\n"
n = n.strip()
##print(n)
f.close()
f = open("QBOutput.txt","w")
f.write(n)
f.close()
