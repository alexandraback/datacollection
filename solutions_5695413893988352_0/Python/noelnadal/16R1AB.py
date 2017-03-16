R = []
f = open("input.txt","r")
T = int(f.readline())

def verif(n,c):
    for i in range(len(c)):
        if n[i] != c[i] and c[i] != "?":
            return False
    return True


for k in range(T):
    print(k)
    C, S = map(str, f.readline().strip().split())
    RC = 42
    RS = 42
    ok = 0
    n = len(C)
    lim = 10**n
    A = "0123456789"
    r = 10**10 
    OKC = []
    for i in range(lim):
        a = ""
        for j in range(n):
            #print(i//(10**j) % 10)
            a = A[i//(10**j) % 10] + a
        if verif(a,C):
            OKC += [a] 
    OKS = []
    for i in range(lim):
        a = ""
        for j in range(n):
            #print(i//(10**j) % 10)
            a = A[i//(10**j) % 10] + a
        if verif(a,S):
            OKS += [a] 
    for x in OKC:
        for y in OKS:
            d = abs(int(x)-int(y))
            if r > d or (r == d and int(RC) > int(x)) or (r == d and int(RC) == int(x) and int(RS) > int(y)):
                r = d
                RC = x
                RS = y
    """for i in range(n):
        c = C[i]
        s = S[i]
        if ok == 0:
            if c == "?" and s == "?":
                RC += "0"
                RS += "0"
            elif c == "?":
                RS += s
                RC += s
            elif s == "?":
                RS += c
                RC += c
            elif c == s:
                RS += s
                RC += s
            elif int(c) > int(s):
                RS += s
                RC += c
                ok = 1
            elif int(c) < int(s):
                RS += s
                RC += c
                ok = -1
        elif ok == 1:
            if c == "?" and s == "?":
                RC += "0"
                RS += "9"
            elif c == "?":
                RS += s
                RC += "0"
            elif s == "?":
                RS += "9"
                RC += c
            else:
                RS += s
                RC += c  
        else:
            if c == "?" and s == "?":
                RC += "9"
                RS += "0"
            elif c == "?":
                RS += s
                RC += "9"
            elif s == "?":
                RS += "0"
                RC += c
            else:
                RS += s
                RC += c  """  
    R = R + [[RC,RS]]
f.close()



f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k][0])+" "+str(R[k][1])+"\n")
f.close()
