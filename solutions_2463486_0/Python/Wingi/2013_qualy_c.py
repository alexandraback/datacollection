import sys, math, os, cPickle, time

class SolutionC(object):

    def __init__(self, maxTen = 14):
        dumpName ="10^%d.dump" % maxTen

        if os.path.exists(dumpName):
            self.solutions = cPickle.load(file(dumpName))
        else:
            self.solutions = self.generate(10 ** maxTen)
            cPickle.dump(self.solutions, file(dumpName, "w"))

        self.maxSol = len(self.solutions)

    def isPalim(self, p):
        pStr = str(p)
        l = len(pStr)
        for i in range(l/2):
            if pStr[i] != pStr[l-1-i]:
                return False
        return True
    #isPalim    

    def generate(self, maxNumber):
        #generate all fair numbers.
        sol = []
        n = 1
        nn = 1
        while nn<=maxNumber:
            nn = n*n
            if self.isPalim(n):
                if self.isPalim(nn):
                    sol.append(nn)
            n += 1
        return sol
    #generate

    def solve(self, a, b):
        return len(filter(lambda n: a<=n and n<=b, self.solutions))

#generate solution: 10**14 for large input1, 10*100 for large input2 ;-)
s = SolutionC(14)

IN = file(sys.argv[1])

for t in range(1, int(IN.readline())+1):
    a,b = map(int, IN.readline().split())
    print "Case #%d: %d" % (t, s.solve(a, b) )
