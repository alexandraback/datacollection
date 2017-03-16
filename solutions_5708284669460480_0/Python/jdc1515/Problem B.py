with open("B-small-attempt0.in") as f:
    lines = f.readlines()

outputname = 'outputBsmall.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

for i in range(cases):
    inputnums = lines[linenum]
    linenum += 1
    K, L, S = [int(j) for j in inputnums.split(" ")]

    keyboard = lines[linenum].strip()
    linenum += 1

    target = lines[linenum].strip()
    linenum += 1

    """
    repnum = L
    for j in range(1, L):
        found = True
        for k in range(L - j):
            if target[k] != target[j+k]:
                found = False
                break
        if found:
            repnum = j
            break
    print(repnum)
    """

    sequence = 0
    points = 0
    maxlen = 0
    for j in range(K ** S):
        outstr = ""
        for k in range(S):
            val = (j // (K ** k)) % K
            outstr += keyboard[val]
        curlen = occurrences(outstr, target)
        maxlen = max(curlen, maxlen)
        points += curlen
    score = maxlen - (points * 1.0 / K ** S)


    f.write("Case #" + str(i+1) + ": " + str(score)+"\n")



f.close()

with open(outputname, 'r') as f:
    print(f.read())
