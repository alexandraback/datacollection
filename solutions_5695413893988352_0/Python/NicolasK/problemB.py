##Problem B

f = open("B-small-attempt1.in")
s = open("salida.txt", 'w')


def resolver(a, b):
    resA = ""
    resB = ""
    i = 0
    puedoAgregar = False
    while i < len(a) and a[i] == "?" and b[i] == "?":
        puedoAgregar = True
        i += 1
    while i < len(a) and not (a[i] != "?" and b[i] != "?" and a[i] != b[i]):
        if a[i] == "?":
            resA += b[i]
            resB += b[i]
        elif b[i] == "?":
            resA += a[i]
            resB += a[i]
        else :
            resA += a[i]
            resB += b[i]
        i += 1
    aEsMasGrande = False
    if i < len(a):
        assert(a[i] != b[i])
        aEsMasGrande = int(a[i]) > int(b[i])
        if puedoAgregar:
            if aEsMasGrande:
                if int(a[i]) - int(b[i]) > 5:
                    aEsMasGrande = False
                    resA = "0" + resA
                    resB = "1" + resB
            else :
                if int(b[i]) - int(a[i]) > 5:
                    aEsMasGrande = True
                    resA = "1" + resA
                    resB = "0" + resB
    while i < len(a):
        if aEsMasGrande:
            if a[i] == "?":
                resA += "0"
            else :
                resA += a[i]
            if b[i] == "?":
                resB += "9"
            else :
                resB += b[i]
        else :
            if a[i] == "?":
                resA += "9"
            else :
                resA += a[i]
            if b[i] == "?":
                resB += "0"
            else :
                resB += b[i]
        i += 1
    if resA == resB and resA == "":
        resA = "0"
        resB = "0"
    while len(resA) != len(a):
        resA = "0" + resA
        resB = "0" + resB
    return resA + " " + resB



cases = int(f.readline())

for case in xrange(1, cases+1):
    s.write("Case #" + str(case) + ": ")
    valores = f.readline().split(" ")
    solucion = resolver(valores[0], valores[1])
    resA = ""
    resB = ""
    sol = solucion
    if "?" not in sol:
        resA = sol.split(" ")[0]
        resB = sol.split(" ")[1]
    else :
        while "?" in sol:
            v = sol.split(" ")
            i = v[0].index("?")
            resA += v[0][::i]
            resB += v[1][::i]
            sol = resolver(v[0][i::], v[1][i::])
        print resA, resB
        v = sol.split(" ")
        resA = resA[0:(len(resA)-len(v[0]))]
        resB = resB[0:(len(resB)-len(v[0]))]
        resA += v[0]
        resB += v[1]
    s.write(resA + " " + resB)
    s.write("\n")


f.close()
s.close()