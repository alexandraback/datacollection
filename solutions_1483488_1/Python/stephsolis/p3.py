def permute(n):    
    out = []
    for i in range(len(n)-1):
        curr = n[i+1::] + n[0:i+1:]
        if not curr in out:
            out.append(n[i+1::] + n[0:i+1:])
    return out

inFile = open("in3.txt")
outFile = open("out3.txt", 'w')

numCases = int(inFile.readline())
for i in range(1, numCases+1):
    line = inFile.readline().split()
    a = int(line[0])
    b = int(line[1])
    
    count = 0
    for n in range(a, b):
        for m in permute(str(n)):
            if n < int(m) and int(m) <= b:
                count += 1
    
    outFile.write("Case #" + str(i) + ": " + str(count) + '\n')