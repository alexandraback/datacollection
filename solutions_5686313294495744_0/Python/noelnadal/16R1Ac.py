R = []
f = open("input.txt","r")
T = int(f.readline())

def unique(i,L,N,c):
    ok = 0
    for j in range(N):
        if j != i and c[0] == L[j][0]:
            ok = 1
            break
    for j in range(N):
        if j != i and c[1] == L[j][1]:
            ok += 1
            break
    return ok

for k in range(T):
    print(k)
    N = int(f.readline().strip())
    L = [list(map(str, f.readline().strip().split(" "))) for _ in range(N)]
    r = 0
    G = [[] for _ in range(N)]
    G1 = [[] for _ in range(N)]
    G2 = [[] for _ in range(N)]
    P = [0 for _ in range(N)]
    D = [0 for _ in range(N)]
    #print(L)
    U = []
    F = []
    for i in range(N):
        if unique(i,L,N,L[i]) < 2:
            U += [L[i]]
        else:
            F += [L[i]]
    for i in range(len(F)-1,-1,-1):
        if unique(-1,U,len(U),F[i]) == 2:
            r += 1
        else:
            U += [F[i]]
    R = R + [r]
f.close()



f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k])+"\n")
f.close()
