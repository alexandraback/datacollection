from sys import stdin

T = int(stdin.readline())
o = ord('A')

def signature(s):
    z = [0 for i in range(ord('A'),ord('Z')+1)]
    for c in s:
        z[ord(c)-o] = z[ord(c)-o]+1
    return z

dig = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

sig = map(lambda s: signature(s), dig)

round1 = {0:ord('Z')-o, 2:ord('W')-o, 4:ord('U')-o, 6:ord('X')-o,
          8:ord('G')-o}
round2 = {1:ord('O')-o, 3:ord('H')-o, 5:ord('F')-o}
round3 = {7:ord('V')-o, 9:ord('I')-o}

for t in range(T):
    s = stdin.readline().strip()
    z = signature(s)
    d = [0 for i in range(10)]
    for k in round1.keys():
        nk = z[round1[k]]
        if nk == 0:
            continue
        d[k] += nk
        z = [z[i]-nk*sig[k][i] for i in range(len(z))]

    for k in round2.keys():
        nk = z[round2[k]]
        if nk == 0:
            continue
        d[k] += nk
        z = [z[i]-nk*sig[k][i] for i in range(len(z))]

    for k in round3.keys():
        nk = z[round3[k]]
        if nk == 0:
            continue
        d[k] += nk
        z = [z[i]-nk*sig[k][i] for i in range(len(z))]

    out = ''
    for i in range(10):
        while d[i] > 0:
            d[i] -= 1
            out = out + str(i)

    print 'Case #{}: {}'.format(t+1, out)
          
          
