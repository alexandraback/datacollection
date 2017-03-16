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
    for t in range(1, T+1):
        l1 = lines[t].split()
        print(l1)
        n = int(l1[0])
        j = int(l1[1])
        fout.write("Case #" + str(t) + ":\n")
        print("Case #" + str(t) + ":")
        j0 = 0
        for i in range(j):
            j1, s = jamcoin(j0, n)
            print(str(i)+": " + s)
            fout.write(s)
            j0 = j1 + 1

def jamcoin(j, n):
    b = bin(j)[2:]
    s = "1" + ("0"*(n-2-len(b))) + b + "1"
    fs = []
    for base in range(2, 11):
        prime, f = isprime(int(s, base))
        if prime:
            return jamcoin(j+1,n)
        fs.append(f)
    sfs = s + " " + " ".join([str(f) for f in fs])+ "\n"
    return j, sfs

primes_db = {}

def isprime(n):
    if n <= 1:
        return False
    if n in primes_db:
        return primes_db[n]
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            primes_db[n] = False, i
            return False, i
    primes_db[n] = True, ""
    return True, ""

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
