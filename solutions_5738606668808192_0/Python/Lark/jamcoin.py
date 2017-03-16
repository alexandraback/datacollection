import random

f = open("jamcoin.small.in", "r")

T = int(f.readline())
for i in range(0, T):
    v = f.readline().split(" ")
    N = int(v[0])
    J = int(v[1])

f.close()


MAX_SEARCH_FACTOR = 999


def isJamCoin(m, fact):
    l = len(m)
    if ( m[0] != '1' or m[l-1] != '1' ):
        return False
    for base in range(2, 11):
        f = isJamCoinBase(m, base)
        if ( f == 0 ):
            return False
        fact[base-2] = f
    return True

def isJamCoinBase(m, base):
    v = getValue(m, base)
    return findFactor(v)

def getValue(m, base):
    l = len(m)
    r = 0
    for i in range(0, l):
        if ( m[i] == '1' ):
            r += pow(base, l-i-1)
    return r

def findFactor(v):
    stop = int(pow(v, 0.5)) + 1
    stop = min(stop, MAX_SEARCH_FACTOR)     # todo: lower stop?
    for f in range(2, stop):
        if ( v % f == 0 ):
            return f

    return 0 # no factor

def create(n):
    s = ""
    for i in range(0, n-2):
        s += str(random.randint(0, 1))
    return '1'+s+'1'



db = set()

M = []
F = []

fact = [0 for i in range(0, 9)]

print "start"
print "T: " + str(T)
print "N: " + str(N)
print "J: " + str(J)

for i in range(0, J):
    print "test: " + str(i)
    retry = True
    tries = 0
    while retry:
        m = create(N)
        success = isJamCoin(m, fact)
        if success and (m not in db):
            retry = False
            db.add(m)
        else:
            retry = True
        tries += 1
    M.append(m)
    F.append(list(fact))
    print m, fact, tries
    
print "end"

f = open("jamcoin.out", "w")

for m in range(0, T):
    f.write("Case #"+str(m+1)+":\n")
    for j in range(0, J):
        f.write(M[j])
        for o in range(0, 9):
            f.write(" " + str(F[j][o]))
        f.write("\n")

        
f.close()

print "done"

