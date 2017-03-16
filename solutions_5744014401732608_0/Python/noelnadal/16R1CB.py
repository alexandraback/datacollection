# You lost the game.
R = []
A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
V = [0, 0, 0, 0, 1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 286, 364, 455, 560, 680, 816, 969, 1140, 1330, 1540, 1771, 2024, 2300, 2600, 2925, 3276, 3654, 4060, 4495, 4960, 5456, 5984, 6545, 7140, 7770, 8436, 9139, 9880, 10660, 11480, 12341, 13244, 14190, 15180, 16215, 17296, 18424]
f = open("input.txt","r")
T = int(f.readline())

def binaire(n,L,b):
    if n <= 1:
        return [0]*(b-len(L)-1) + L + [n]
    else:
        return binaire(n//2,L + [n%2],b)
    
def cherche(B,M,i,r,v):
    if v > M:
        return v + 1
    if i == B-1:
        return v + 1
    else:
        for j in range(i+1,B):
            if r[i][j] == 1:
                v = cherche(B,M,j,r,v)
        return v

r = [[0,0,1,1,0],[0,0,0,0,0],[0,0,0,1,0],[0,0,0,0,1],[0,0,0,0,0]]
for k in range(T):
    print(k)
    B,M = map(int, f.readline().strip().split())
    r = [[0 for _ in range(B)] for _ in range(B)]
    w = 1
    r[0][B-1] = 1
    lim = 2**(B*(B-1)//2)
    ok = 0
    for i in range(lim):
        L = binaire(i,[],B*(B-1)//2)
        s = 0
        for i in range(B-1):
            for j in range(i+1,B):
                r[i][j] = L[s]
                s += 1
        v = cherche(B,M,0,r,0)
        if v == M:
            ok = 1
            break
    if ok:
        R = R + [[B,r]]
    else:
        R = R + [[0,"IMPOSSIBLE"]]
    
"""def verif(r,M,B):
    A = [0 for _ in range(B)]
    for i in range(1,B-2):
        for j in range(i+1,B-1):
            if r[i][j]:
                A[j] += 1

for k in range(T):
    print(k)
    B,M = map(int, f.readline().strip().split())
    r = [[0 for _ in range(B)] for _ in range(B)]
    w = 1
    r[0][B-1] = 1
    if V[B] < M:
        r = "IMPOSSIBLE"
    else:
        for i in range(1,B-1):
            if w == M:
                break
            w += 1
            r[0][i] = 1
            r[i][B-1] = 1
        for i in range(1,B-2):
            for j in range(i+1,B-1):
                if w == M:
                    break
                r[i][j] = 1
                w += 1
            if w == M:
                break
    R = R + [[B,r]]                
            
"""
f.close()
f = open("output.txt","w")
for k in range(T):
    if R[k][1] == "IMPOSSIBLE":
        f.write("Case #"+str(k+1)+": IMPOSSIBLE\n")
    else:
        f.write("Case #"+str(k+1)+": POSSIBLE\n")
        for i in range(R[k][0]):
            for j in range(R[k][0]):
                f.write(str(R[k][1][i][j]))
            f.write("\n")
f.close()

    
