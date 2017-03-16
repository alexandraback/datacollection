'''
Created on May 6, 2011

@author: jirasak
'''

class A():
    def __init__(self):
        self.classes = {}
        self.data = []

    def getClasses(self, l):
#        print 'fillClasses %d' % l
#        print l
#        print self.data
#        print self.data[l]
        if self.classes.has_key(l):
            return self.classes[l]
        result = []
        for p in self.data[l]:
            a = [p]
            parents = self.getClasses(p)
            for pp in parents:
                a.extend(pp)
            result.append(a)
        self.classes[l] = result
        return result
    
    def containsDiamond(self, listI, listJ):
        #print listI
        #print listJ
        for a in listI:
            if a not in listJ:
                continue
            indexI = listI.index(a)
            indexJ = listJ.index(a)
            #print a, listI[:indexI], listJ[:indexJ]
            if listI[:indexI] != listJ[:indexJ]:
                return True
        return False
    
    def containsDiamondAll(self, listOfSets):
        for i in range(len(listOfSets)-1):
            for j in range(i+1, len(listOfSets)):
                listI = listOfSets[i]
                listJ = listOfSets[j]
                if self.containsDiamond(listI, listJ):
                    return True
        return False                    
    
    def hasDiamond(self):
        #print self.classes
        for k in self.classes.values():
            if self.containsDiamondAll(k):
                return True
        return False
        
    
    def solve(self, i, num, lines):
        lines = [[int(y) - 1 for y in x.strip().split(' ')][1:] for x in lines]
        self.data = lines
        self.classes = {}
        # create class path
        for l in range(len(lines)):
            self.getClasses(l)
        #print self.classes
        if(self.hasDiamond()):
            return 'Yes'
        return 'No'

if __name__ == '__main__':
    fIn = file('A-small-attempt1.in')
    inLines = fIn.readlines()
    fIn.close()
    
    inLines = inLines[1:]
    numLines = len(inLines)
    i = 0
    numCase = 0
    while i < numLines:
        num = int(inLines[i].strip())
        lines = inLines[i+1:i+1+num]
        i += 1 + num
        numCase += 1
#        print lines
        a = A()
        data = a.solve(i, num, lines)
        print 'Case #%s: %s' % (numCase, data)
    