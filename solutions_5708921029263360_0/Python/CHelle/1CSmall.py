f = open("1CsInput.in","r")
T = int(f.readline())
##import sys
##T = int(sys.stdin.readline())
n = ""
for i in range (0,T):
    P = f.readline().split()
##    P = sys.stdin.readline().split()
    J = int(P[0])
    S = int(P[2])
    K = int(P[3])
    P = int(P[1])    
    n = n+"Case #"+str(i+1)+": "+str(J*P*min(S,K))+"\n"
    for j in range (0,J*P*min(S,K)):
        a = j//(J*P)
        b = (j-a*J*P)//P+1
        c = j-a*J*P-(b-1)*P+1
        n = n + str(b)+" "+str(c)+" "+str((((b+c)%P)+a)%S+1)+"\n"
n = n.strip()
##print(n)
f.close()
f = open("1CsOutput.txt","w")
f.write(n)
f.close()
