R = []
f = open("input.txt","r")
T = int(f.readline())
for k in range(T):
    s = str(f.readline().strip())
    L = [s[i] for i in range(len(s))]
    P = [0 for _ in range(10)]
    ok = 1
    while ok:
        ok = 0
        if L.count("Z"):
            P[0] += 1
            ok = 1
            del(L[L.index("Z")])
            del(L[L.index("E")])
            del(L[L.index("R")])
            del(L[L.index("O")])
        if L.count("W"):
            P[2] += 1
            ok = 1
            del(L[L.index("T")])
            del(L[L.index("W")])
            del(L[L.index("O")])
        if L.count("X"):
            P[6] += 1
            ok = 1
            del(L[L.index("S")])
            del(L[L.index("I")])
            del(L[L.index("X")])
    ok = 1
    while ok:
        ok = 0
        if L.count("S"):
            P[7] += 1
            ok = 1
            del(L[L.index("S")])
            del(L[L.index("E")])
            del(L[L.index("V")])
            del(L[L.index("E")])
            del(L[L.index("N")])
    ok = 1
    while ok:
        ok = 0
        if L.count("V"):
            P[5] += 1
            ok = 1
            del(L[L.index("F")])
            del(L[L.index("I")])
            del(L[L.index("V")])
            del(L[L.index("E")])
    ok = 1
    while ok:
        ok = 0
        if L.count("F"):
            P[4] += 1
            ok = 1
            del(L[L.index("F")])
            del(L[L.index("O")])
            del(L[L.index("U")])
            del(L[L.index("R")])
    ok = 1
    while ok:
        ok = 0
        if L.count("O"):
            P[1] += 1
            ok = 1
            del(L[L.index("O")])
            del(L[L.index("N")])
            del(L[L.index("E")])
        if L.count("T") and L.count("R"):
            P[3] += 1
            ok = 1
            del(L[L.index("T")])
            del(L[L.index("H")])
            del(L[L.index("R")])
            del(L[L.index("E")])
            del(L[L.index("E")])
    ok = 1
    while ok:
        ok = 0
        if L.count("H"):
            P[8] += 1
            ok = 1
            del(L[L.index("E")])
            del(L[L.index("I")])
            del(L[L.index("G")])
            del(L[L.index("H")])
            del(L[L.index("T")])
    ok = 1
    while ok:
        ok = 0
        if L.count("I"):
            P[9] += 1
            ok = 1
            del(L[L.index("N")])
            del(L[L.index("I")])
            del(L[L.index("N")])
            del(L[L.index("E")])
    r = ""
    D = "0123456789"
    print(P)
    for i in range(10):
        r = r + D[i]*P[i]
    R = R + [r]
f.close()



f = open("output.txt","w")
for k in range(T):
    f.write("Case #"+str(k+1)+": "+str(R[k])+"\n")
f.close()
