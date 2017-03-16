# You lost the game.
from random import *
R = []
A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
f = open("input.txt","r")
T = int(f.readline())

H = [[1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 2], [1, 2, 3], [1, 3, 3], [2, 2, 2], [2, 2, 3], [2, 3, 3], [3, 3, 3]]

for k in range(T):
    print(k)
    J,P,S,K = map(int, f.readline().strip().split())

    L = [[J,0],[P,1],[S,2]]
    def ct(a):
        return a[0]
    L.sort(key=ct)
    a = L[0][0]
    ai = L[0][1]
    b = L[1][0]
    bi = L[1][1]
    ci = L[2][1]
    r = []
    if J*P*S < K*a*b:
        rep = J*P*S
        for i in range(J):
            for j in range(P):
                for l in range(S):
                    r += [[i+1,j+1,l+1]]
    else:
        rep = K*a*b
        
        for l in range(K):
            for i in range(a):
                for j in range(b):
                    t = [0,0,0]
                    t[ai] = i+1
                    t[bi] = j+1
                    t[ci] = randint(1,S)
                    r += [t]
    shuffle(r)
    R = R + [[rep]+r]
            

f.close()
f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k][0])+"\n")
    for i in range(1,R[k][0]+1):
        f.write(str(R[k][i][0])+" "+str(R[k][i][1])+" "+str(R[k][i][2])+"\n")
f.close()

    
