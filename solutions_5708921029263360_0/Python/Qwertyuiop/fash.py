def validate(sol, j, p, s, K):
    if (j,p,s) in sol: return False
    jp={}
    ps={}
    js={}
    for (J,P,S) in sol:
        try: jp[J+P]+=1
        except: jp[J+P]=1
        try: ps[P+S]+=1
        except: ps[P+S]=1
        try: js[J+S]+=1
        except: js[J+S]=1
    if j+p in jp and jp[j+p]==K: return False
    if p+s in ps and ps[p+s]==K: return False
    if j+s in js and js[j+s]==K: return False
    return True

def solve(J,P,S,K):
    ## this is a list of tuples
    sol=[]
    J=map(str, range(1,J+1))
    P=map(str, range(1,P+1))
    S=map(str, range(1,S+1))
    for j in J:
        for p in P:
            for s in S:
                if validate(sol, j, p, s, K):
                    sol.append((j,p,s))
    sol=map(lambda x: " ".join(x),sol)
    return str(len(sol))+"\n"+"\n".join(sol)

import sys
f = open(sys.argv[1], "r")
F = open(sys.argv[1]+".out", "w")
for i in range(int(f.readline())):
    (J,P,S,K)=map(int, f.readline().rstrip().split(" "))
    F.write("Case #%d: %s\n" % (i+1, solve(J,P,S,K)))
F.close()