input_file = "C-small-attempt0.in"
output_file = "C-small-attempt0.out"

in_f = open(input_file)
T_read = False
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if not T_read:
        T = int(sl)
        T_read = True
        continue
    NJ = l.split(' ')
    tcs.append([int(NJ[0]), int(NJ[1])])
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, res, J):
    out_f.write("Case #" + str(tcn) + ":\n")
    for r in res:
        l = r[0]
        for i in range(1, 10):
            l = l + ' ' + str(r[i])
        out_f.write(l + "\n")

import math

def getDiv(n):
    if n < 2:
        return -1
    m = int(math.sqrt(n))
    if m == 1:
        return -1
    for d in range (2, m + 1):
        if n % d == 0:
            return d
    return -1


def toDec(cjc, base):
    b = 1
    r = 0
    for ch in cjc:
        r += b * ch
        b *= base
    return r

def toCandJamCoin(dec):
    if dec % 2 == 0:
        return []
    r = []
    n = dec
    while n != 0:
        r.append(n % 2)
        n = n / 2
    l = len(r)
    if l < 2 or r[l - 1] == 0:
        return []
    return r

def JamCoinToStr(jc):
    s = ""
    l = len(jc)
    for i in range(0, l):
        s += str(jc[l - i - 1])
    return s

def SolveTestCase(N, J):
    max = int(math.pow(2, N))
    r = []
    i = int(math.pow(2, N - 1))
    count = 0
    while i < max:
        if count == J:
            break
        cjc = toCandJamCoin(i)
        if len(cjc) == 0:
            i += 1
            continue
        jc = [""]
        prime = False
        for b in range(2, 11):
            div = getDiv(toDec(cjc, b))
            if div == -1:
                prime = True
                break
            else:
                jc.append(div)
        if not prime:
            jc[0] = JamCoinToStr(cjc)
            print jc
            count += 1
            r.append(jc)
        i += 1
    return r

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i][0], tcs[i][1])
    OutputTestCase(i + 1, r, tcs[i][1])

out_f.close()

