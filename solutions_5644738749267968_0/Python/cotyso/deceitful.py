from __future__ import print_function

outFile = open("deceitful.out", "w")

#lines = list(open("deceitful.in"))
lines = list(open("D-small-attempt0.in"))
#lines = list(open("C-large.in"))
testCount = int(lines.pop(0))

for test in range(1, testCount+1):
    blocks = int(lines.pop(0))
    blocksN = sorted([float(x) for x in str.split(lines.pop(0))])
    blocksK = sorted([float(x) for x in str.split(lines.pop(0))])
    
    #print(blocksN)
    #print(blocksK)
    
    countW = 0
    blocksKK = [x for x in blocksK]
    for i in range(blocks):
        choosenN = blocksN[blocks-i-1]
        if choosenN > blocksKK[-1]:
            countW += 1
            blocksKK.pop(0)
        else:
            blocksKK.remove(min([x for x in blocksKK if x > choosenN]))

    countD = 0
    ks, ke = 0, blocks-1
    for i in range(blocks):
        choosenN = blocksN[i]
        if choosenN < blocksK[ks]:
            ke -= 1
        else:
            countD += 1
            ks += 1

    print("Case #{}: {} {}".format(test, countD, countW))
    outFile.write("Case #{}: {} {}\n".format(test, countD, countW))

outFile.close()

