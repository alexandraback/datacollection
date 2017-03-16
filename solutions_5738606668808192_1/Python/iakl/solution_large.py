input_file = "C-large.in"
output_file = "C-large.out"

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
    d = 2
    # note: this is a simplification made in order to solve the large problem -
    # we only check potential dividors up to 19, thus avoiding spending much time
    # on verification of large numbers, that'll possibly turn out to be prime;
    # if we need more jamcoins, we can expand this range beyond 19, up to m, however
    # it was not required in order to solve the particular large problem and hence
    # is not implemented here
    while d < m + 1 and d < 20:
        if n % d == 0:
            return d
        d += 1
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

def getNearestPow2(J):
    p = 1
    while p < J:
        p *= 2
    return p

def SolveTestCase(N, J):
    mx = int(math.pow(2, N))
    r = []
    grade = getNearestPow2(J)
    while len(r) < J and grade * 2 <= mx:
        # it's a simple observation, that numbers a * 2^b + 1(in decimal representation)
        # with b large rather than small more often turn out to be jamcoins, so we'll check
        # the cases for large b first
        i = (mx / 2) + 1
        j = 0
        delta = i / grade
        while j < grade:
            if len(r) == J:
                break
            if j % 2 == 0:
                #checked previously
                j += 1
                i += delta
                continue
            cjc = toCandJamCoin(i)
            if len(cjc) == 0:
                j += 1
                i += delta
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
                r.append(jc)
            j += 1
            i += delta
        grade *= 2
    # if J is not to large compared to 2^N, we'll most likely have len(r) == J here
    return r

print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i][0], tcs[i][1])
    OutputTestCase(i + 1, r, len(r))

out_f.close()

