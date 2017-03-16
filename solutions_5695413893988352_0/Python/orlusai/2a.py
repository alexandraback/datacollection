inFile = open("B-small-attempt0.in")
outFile = open("2.out", "w")

inFile.readline()

def nums(orig):
    
    numWithZeros = sum(int(orig[-i-1])*(10**i) for i in range(len(orig)) if orig[-i-1]!="?")
    blankPowers = [10**(len(orig)-i-1) for i in range(len(orig)) if orig[i]=="?"]

    vals = []

    numOfBlanks = orig.count("?")

    if numOfBlanks==0:
        vals = [numWithZeros]
    elif numOfBlanks==1:
        for i in range(10):
            vals.append(numWithZeros+i*blankPowers[0])
    elif numOfBlanks==2:
        for i in range(10):
            for j in range(10):
                vals.append(numWithZeros+i*blankPowers[0]+j*blankPowers[1])
    elif numOfBlanks==3:
        for i in range(10):
            for j in range(10):
                for k in range(10):
                    vals.append(numWithZeros+i*blankPowers[0]+j*blankPowers[1]+k*blankPowers[2])

    return vals

cnt = 1

for line in inFile:
    [orig1, orig2] = line.rstrip().split(" ")
    
    vals1 = nums(orig1)
    vals2 = nums(orig2)

    minComb = ""
    minDif = 999999999999

    for val1 in vals1:
        for val2 in vals2:
            if(abs(val1-val2) < minDif):
                minDif = abs(val1-val2)
                minComb = [val1, val2]

    print("Case #" + str(cnt) + ":", str(minComb[0]).rjust(len(orig1), "0"), str(minComb[1]).rjust(len(orig1), "0"), file=outFile)

    cnt += 1

outFile.close()
