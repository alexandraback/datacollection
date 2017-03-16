f = open("QDInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    S = f.readline().split()
##    S = sys.stdin.readline().split()
    K = int(S[0])
    C = int(S[1])
    S = int(S[2])
    n = n+"Case #"+str(i+1)+":"
    if S*C < K:
        n = n+" IMPOSSIBLE"
    else:
        j = 1
        for i in range (0,(K+C-1)//C):
            k = 0
            m = 0
            while (k < C) and (j < K+1):
               m = m+(j-1)*K**k
               j = j+1
               k = k+1
            n = n+" "+str(m+1)
    n = n+"\n"
n = n.strip()
##print(n)
f.close()
f = open("QDOutput.txt","w")
f.write(n)
f.close()
