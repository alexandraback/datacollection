def a (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    for t in range(1, T+1):
        line = lines[t]
        print("line " + str(t))
        fout.write("Case #" + str(t) + ": " + word(line))

def word(line):
    acc = ""
    for c in line:
        if acc == "":
            acc = c
        elif acc[0]<=c:
            acc = c + acc
        else:
            acc = acc + c
    return acc

def b (fname):
    fin = open(fname + ".in")
    lines = fin.readlines()
    T = int(lines[0])
    fout = open(fname + ".out", "w")
    lnum = 1
    for t in range(1, T+1):
        n = int(lines[lnum])
        lists = []
        for i in range(1, n*2):
            lnum = lnum + 1
            lists.append([int(ht) for ht in lines[lnum].split()])
        lnum = lnum + 1
        print (lists)
        fout.write("Case #" + str(t) + ": " + missing(lists) + "\n")
        print(t)

def missing(lists):
    ns = {}
    for lst in lists:
        for n in lst:
            if n in ns:
                ns[n] = ns[n] + 1
            else:
                ns[n] = 1
    odds = []
    for n in ns:
        if ns[n]%2 != 0:
            odds.append(n)
    odds.sort()
    return " ".join([str(n) for n in odds])


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
