with open("C-small-attempt2.in") as f:
    lines = f.readlines()

outputname = 'outputCsmall2.txt'
f = open(outputname, 'w')

cases = int(lines[0])
linenum = 1

def log2(x):
    p = 0
    while 2**p <= x:
        p += 1
    return p - 1

def cnumpos(C, D, V, vals):
    possible = [False] * (V+1)
    numpos = 0
    counts = 0
    while counts < (C + 1) ** D:
        cursum = 0
        for j in range(D):
            curpow = (C + 1) ** j
            curnum = (counts // curpow) % (C + 1)
            cursum += curnum * vals[j]
        if cursum > V:
            counts += 1
            continue
        if not possible[cursum]:
            possible[cursum] = True
            numpos += 1
        counts += 1

    maxsize = 0
    start = 0
    for j in range(V+2):
        if (j == V + 1) or possible[j]:
            end = j
            diff = end - start
            start = j
            maxsize = max(diff, maxsize)
    #print(maxsize)
    #print(log2(maxsize))


    #numpos = numpos - 1
    return log2(maxsize)

for i in range(cases):
    nums = lines[linenum].split(" ")
    nums = [int(j) for j in nums]
    linenum += 1

    C, D, V = nums

    nums = lines[linenum].split(" ")
    nums = [int(j) for j in nums]
    linenum += 1

    vals = nums

    use = 0
    for j in range(D):
        use += 2 ** (vals[j] - 1)

    f.write("Case #" + str(i+1) + ": " + str(cnumpos(C,D,V, vals))+"\n")
    """
    curuse = 0
    minval = 99999999
    while curuse < 2 ** V:
        curuse2 = curuse | use
        newvals = []
        for j in range(V):
            if curuse2 & (2 ** j):
                newvals.append(j+1)
        newD = len(newvals)
        curuse += 1
        numpos = cnumpos(C, newD, V, newvals)
        if numpos == V:
            curcount = bin(curuse2).count("1") - D
            minval = min(curcount, minval)
            break
    """

    #f.write("Case #" + str(i+1) + ": " + str(minval)+"\n")



f.close()

with open(outputname, 'r') as f:
    print(f.read())
    pass
