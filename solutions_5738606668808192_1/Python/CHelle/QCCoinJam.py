f = open("QClInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    S = f.readline().split()
##    S = sys.stdin.readline().split()
    N = int(S[0])
    J = int(S[1])
    n = n+"Case #"+str(i+1)+": \n"
    for i in range (0,J):
        i1 = i
        n = n+"11"
        for j in range (0,(N-4)//2):
            n = n+str(i1%2)+str(i1%2)
            i1 = i1//2
        n = n+"11 3 4 5 6 7 8 9 10 11\n"
    n = n.strip()
##print(n)
f.close()
f = open("QClOutput.txt","w")
f.write(n)
f.close()
