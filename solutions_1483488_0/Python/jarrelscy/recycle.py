import math
fp = open('C-small-attempt0.in', 'r')
fp2 = open('output.txt', 'w')
numCases = int(fp.readline())

for mastercount in range(numCases):
    inStr = fp.readline()
    inList = inStr.split(" ")
    lowerBound = int(inList[0])
    upperBound = int(inList[1])
    numRecycled = 0
    alreadyIn = {}
    bounds = range(lowerBound, upperBound+1)
    for c in bounds:
        alreadyIn[c] = []
    for c in bounds:
        l = list(str(c))
        offset = 1
        
        for i in range(len(l)-1):
            offset = i+1
            cycledList = []
            for count in range(len(l)):
                cycledList.append(l[(count+offset)%len(l)])
            a = int("".join(cycledList))
            if(a in bounds and len(str(a)) == len(str(c)) and a != c):
                if(not (c in alreadyIn[a]) and not (a in alreadyIn[c])):
                    #print a, c
                    numRecycled += 1
                    alreadyIn[a].append(c)
                    alreadyIn[c].append(a)
    print numRecycled
    fp2.write("Case #"+str(mastercount+1)+": " + str(numRecycled)+"\n")
    
    
fp.close()
fp2.close()
