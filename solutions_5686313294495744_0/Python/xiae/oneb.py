def a (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        line = lines[t]
        print("line " + str(t))
        fout.write("Case #" + str(t) + ": " + phone(line) + "\n")

def phone(line):
    cs = list(line)
    map1 = {"Z": (0, "ZERO"), "W": (2, "TWO"), "U": (4, "FOUR"), "X": (6, "SIX"), "G": (8, "EIGHT")}
    map2 = {"O": (1, "ONE"), "H": (3, "THREE"), "F": (5, "FIVE"), "S" : (7, "SEVEN")}
    map3 = {"I": (9, "NINE")}
    digits = [0] * 10
    for m in (map1, map2, map3):
        for c in m:
            while c in cs:
                digit, letters = m[c]
                digits[digit] = digits[digit] + 1
                for l in letters:
                    cs.remove(l)
    return "".join([str(n) * digits[n] for n in range(10)])


def b (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    lnum = 1
    for t in range(1, T+1):
        line = lines[t]
        blanks = lines[t].split()
        fout.write("Case #" + str(t) + ": " + scores(blanks) + "\n")
        print(t)

def scores(blanks):
    coders = []
    coders = blanks[0]
    jammers = blanks[1]
    mindiff = (float("inf"), (None, None))
    qcs = coders.count("?")
    qjs = jammers.count("?")
    for i in range(10**qcs):
        si = str(i)
        k = 0
        coderscore = ""
        for j in range(len(coders)):
            if coders[j] == "?":
                if qcs - k > len(si):
                    digit = "0"
                else:
                    digit = si[k - (qcs - len(si))]
                k = k + 1
            else:
                digit = coders[j]
            coderscore = coderscore + digit
        for x in range(10 ** qjs):
            sx = str(x)
            z = 0
            jammerscore = ""
            for y in range(len(jammers)):
                if jammers[y] == "?":
                    if qjs - z > len(sx):
                        digit = "0"
                    else:
                        digit = sx[z - (qjs - len(sx))]
                    z = z + 1
                else:
                    digit = jammers[y]
                jammerscore = jammerscore + digit
            diff = abs(int(coderscore) - int(jammerscore))
            # print (diff, (coderscore, jammerscore))
            # input()
            if diff < mindiff[0]:
                mindiff = (diff, (coderscore, jammerscore))
                # print ("min: " + str(mindiff))
        bestdiff, (bestcoderscore, bestjammerscore) = mindiff
    return bestcoderscore + " " + bestjammerscore



def c (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    i = 1
    for t in range(1, T+1):
        N = int(lines[i])
        for n in range(N):
            topics = [l.split() for l in lines[i+1:i + N+1]]
        i = i + N +1
        fout.write("Case #" + str(t) + ": " + fakes(topics)+ "\n")
        print("Case #" + str(t) + ":")

def fakes(topics):
    print (topics)
    firstwords = {}
    secondwords = {}
    for topic in topics:
        firstword = topic[0]
        secondword = topic[1]
        if firstword in firstwords:
            firstwords[firstword] = firstwords[firstword] + 1
        else:
            firstwords[firstword] = 1
        if secondword in secondwords:
            secondwords[secondword] = secondwords[secondword] + 1
        else:
            secondwords[secondword] = 1
    dupw1s = list(filter(lambda n: firstwords[n] > 1, firstwords))
    # print(list(dupw1s))
    dupw2s = list(filter(lambda n: secondwords[n] > 1, secondwords))
    # print(list(dupw2s))
    fakes = 0
    for w1 in list(dupw1s):
        # print(w1)
        for w2 in list(dupw2s):
            # print(w2)
            # print (str([w1, w2]) + ": " + str([w1, w2] in topics))
            if [w1, w2] in topics:
                print(w1, w2)
                fakes = fakes + 1
    return str(fakes)

def d (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        l1 = lines[t].split()
        k = int(l1[0])
        c = int(l1[1])
        s = int(l1[2])
        fout.write("Case #" + str(t) + ": ")
        print ("Case #" + str(t) + ":")
        fout.write(fractile(k,c,s))
        fout.write("\n")

def fractile(k,c,s):
    if s >= k:
        ts = [str(n*(k**(c-1)) + 1) for n in range(k)]
        print(ts)
        return " ".join(ts)
    return "IMPOSSIBLE"
