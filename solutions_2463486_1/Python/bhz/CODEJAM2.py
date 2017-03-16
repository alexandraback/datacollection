# generate ROOTS of fair and square numbers thru 1E100
def ispal(e): return str(e) == str(e)[::-1]
#for e in range(1,10**7):
#    if ispal(e) and ispal(e*e): print e

MAX = 7
seedsO = [1, 2]
seedsE = [1, 2]
L = [9]
while len(seedsO + seedsE) > 0:
    # odds
    temp = []
    for i in seedsO:
        e = int(str(i) + str(i)[::-1][1:])
        if ispal(e) and ispal(e*e) and e < 10 ** MAX:
            L.append(e*e)
            temp.append(i)
    seedsO = temp
    temp = []
    for k in seedsO: temp += [10*k, 10*k + 1, 10*k + 2]
    seedsO = temp
    # evens
    temp = []
    for i in seedsE:
        e = int(str(i) + str(i)[::-1])
        if ispal(e) and ispal(e*e) and e < 10 ** MAX:
            L.append(e*e)
            temp.append(i)
    seedsE = temp
    temp = []
    for k in seedsE: temp += [10*k, 10*k + 1, 10*k + 2]
    seedsE = temp
f = open('DATA2.txt', 'w')
for e in sorted(L):
    f.write(str(e) + '\n')
f.close()
