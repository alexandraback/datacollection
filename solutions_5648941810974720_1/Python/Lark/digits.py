f = open("digits.large.in", "r")

T = int(f.readline())
C = []

for i in range(0, T):
    C.append(f.readline().strip())

f.close()


def remove(inp, search, word):
    out = inp
    i = 0
    while ( search in out ):
        out = removeWord(out, word)
        i+=1
    return (i, out)

def removeWord(inp, word):
    out = inp
    for ltr in word:
        out = out.replace(ltr, "", 1)
    return out

def number(S):

    arrOut = []

    for i in range(0, 10):
        arrOut.append(0)
        
    k = remove(S, "Z", "ZERO")
    arrOut[0] = k[0]
    S = k[1]

    k = remove(S, "W", "TWO")
    arrOut[2] = k[0]
    S = k[1]

    k = remove(S, "U", "FOUR")
    arrOut[4] = k[0]
    S = k[1]

    k = remove(S, "X", "SIX")
    arrOut[6] = k[0]
    S = k[1]

    k = remove(S, "G", "EIGHT")
    arrOut[8] = k[0]
    S = k[1]

    k = remove(S, "O", "ONE")
    arrOut[1] = k[0]
    S = k[1]

    k = remove(S, "T", "THREE")
    arrOut[3] = k[0]
    S = k[1]

    k = remove(S, "F", "FIVE")
    arrOut[5] = k[0]
    S = k[1]

    k = remove(S, "S", "SEVEN")
    arrOut[7] = k[0]
    S = k[1]

    k = remove(S, "I", "NINE")
    arrOut[9] = k[0]
    S = k[1]

    out = ""
    for i in range(0, 10):
        out += str(i)*arrOut[i]

    return out


f = open("digits.out", "w")

for m in range(0, T):
    f.write("Case #" + str(m + 1) + ": " + number(C[m]) + "\n")
        
f.close()

print "done"
