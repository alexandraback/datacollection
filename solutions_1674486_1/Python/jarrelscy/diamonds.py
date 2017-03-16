cstack = []

class myClass:
    global cstack
    
    def __call__(self):
        1
    def __init__(self):
        self.inheritsFrom = []
        self.checked = {}
    def inheritFrom(self, i):
        self.inheritsFrom.append(i)
    def checkInheritedFrom(self, i):
        return (i in self.inheritsFrom)
    def checkPathTo(self, i, totalNumber):
        if i in self.checked:
            return self.checked[i]
        if self == cstack[i]:
            return 1
        thisNumber = 0
        for child in self.inheritsFrom:
            thisNumber += cstack[child].checkPathTo(i, totalNumber)        
        self.checked[i] = totalNumber+thisNumber
        return totalNumber+thisNumber
                
        

            
fp = open('A-large.in', 'r')
fp2 = open('output.txt', 'w')
numCases = int(fp.readline())

for c in range(numCases):
    numClasses = int(fp.readline())
    cstack = []
    for d in range(numClasses):
        cstack.append(myClass())

    for d in range(numClasses):
        inStr = fp.readline().split(" ")        
        for s in inStr[1:]:
            cstack[d].inheritFrom(int(s) - 1)

    diamond = False
    for d in range(numClasses):
        for e in range(numClasses):
            if cstack[d].checkPathTo(e, 0) > 1:
                diamond = True
                break

    print "Case #"+str(c+1)+": " + str(diamond), numClasses
    if(diamond):
        fp2.write("Case #"+str(c+1)+": " + "Yes" +"\n")
    else:
        fp2.write("Case #"+str(c+1)+": " + "No" +"\n")

fp.close()
fp2.close()
