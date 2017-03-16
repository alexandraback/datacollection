f = open("C-small-attempt0.in", 'r')
allfile = f.read()
lines = allfile.split("\n")
output = []

def addOne(binary, maxOne):
    carry = True
    count = 0
    while carry:
        num = binary[count]
        if num == 1:
            binary[count] = 0
            carry = True
        elif num == 0:
            binary[count] = 1
            carry = False
            maxOne = max(maxOne, count)
        count+=1

def indexSums(tempSum, sums):
    for i in xrange(len(sums)):
        s = sums[i][0]
        if tempSum == s:
            return i
    return -1

def removeLower(sums, maxO):
    return [sums[i] for i in xrange(len(sums)-1,-1,-1) if sums[i][0] > maxO]

T = int(lines.pop(0))
for Tcount in xrange(T):
    line = lines.pop(0).split(" ")
    N = int(line[0])
    nums = sorted([int(n) for n in line[1:]])
    binary = [0]*N
    maxOne = 0
    addOne(binary, maxOne)
    base = binary[:]
    sums = []
    matched = None
    tempSum = 0
    while matched == None:
        tempSum = sum([binary[i] == 1 and nums[i] or 0 for i in xrange(N)])
        index = indexSums(tempSum, sums)
        if index != -1:
            matched = index
        else:
            sums.append((tempSum, binary[:]))
            addOne(binary, maxOne)
            temp = sums[:]
            sums = removeLower(sums, nums[maxOne])
    out1 = [nums[i] for i in xrange(N) if binary[i] == 1]
    out2 = [nums[i] for i in xrange(N) if sums[index][1][i] == 1]
    output.append((out1, out2))
    
def outrawr(outarray):
    outstring = ""
    for s in outarray:
        outstring += str(s) + " "
    return outstring[:-1]
f = open("problemC.out", 'w')
for x in xrange(len(output)):
    out = "Case #" + str(x+1) + ":\n" + outrawr(output[x][0]) + "\n" + outrawr(output[x][1]) + "\n"
    f.write(out)
    print(out)
