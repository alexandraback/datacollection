def match(x,y):
    for i in range(len(x)):
        if x[i] != '?' and x[i] != y[i]:
            return False
    return True

T=int(input())
for t in range(T):
    C,J=input().split()
    L=len(C)

    B,mc,mj=10**10,10**10,10**10
    for a in range(10**L):
        if match(C,str(a).zfill(L)):
            for b in range(10**L):
                if match(J,str(b).zfill(L)):
                    B,mc,mj=min((B,mc,mj),(abs(b-a),a,b))
    print("Case #%d: %s %s" % (t+1, str(mc).zfill(L), str(mj).zfill(L)))
