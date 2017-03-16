f = open("QAInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    N = int(f.readline())
##    N = int(sys.stdin.readline())
    m = 0
    if N == 0:
        m = "INSOMNIA"
    else:
        A = [0,0,0,0,0,0,0,0,0,0]
        while A != [1,1,1,1,1,1,1,1,1,1]:
            m = m+N
            for l in str(m):
                A[int(l)] = 1
    n = n+"Case #"+str(i+1)+": "+str(m)+"\n"
n = n.strip()
##print(n)
f.close()
f = open("QAOutput.txt","w")
f.write(n)
f.close()
