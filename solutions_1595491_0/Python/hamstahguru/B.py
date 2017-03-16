import sys
import math

valid = []
surprising = []
sums = {}

for i in range(0,11):
    for j in range(0,11):
        for k in range(0,11):
            t = sorted([i,j,k])
            
            max_dist = max([abs(i-j), abs(i-k), abs(j-k)])
            
            if max_dist < 2:
                valid.append(t)
            elif max_dist == 2:
                surprising.append(t)
            else: 
                continue
            s = sum(t)
            if not s in sums:
                sums[s] = []
            if t not in sums[s]:
                sums[s].append(t)

# for v in valid:
#     print v

# for s in surprising:
#     print s," *"



class Test:
    
    def __init__(self, googlers, surp, p, data):
        self.surp = surp
        self.data = data
        self.p = p
        self.googlers = googlers

    def solve(self):
        # print "----------------------------------------------------------"
        count = 0
        # print "p: ",self.p
        # print "surp: ",self.surp
        left_surprising = self.surp
        for d in self.data:

            possible_triplets = sums[d]
            # print "d: ",d
            foundValid = False

            for t in possible_triplets:
                if max([t[0],t[1],t[2]]) < self.p:
                    continue
                if t in valid:
                    # print "\t",t
                    foundValid = True
                    count += 1
                    break
            if not foundValid and left_surprising > 0:
                for t in possible_triplets:
                    if max([t[0],t[1],t[2]]) < self.p:
                        continue
                    if t in surprising:
                        # print "\t",t," *"
                        count += 1
                        left_surprising -= 1
                        break
                    
                
        
        return count


def loadTests(filename):
    tests = []

    f = open(filename)

    N = int(f.readline())
    for i in range(N):
        line = map(int,f.readline().split(" "))
        googlers = line[0]
        surp = line[1]
        p = line[2]
        data = line[3:]

        tests.append(Test(googlers,surp,p, data))
    return tests

if len(sys.argv) != 2:
    print "usage: %s datafile"%(sys.argv[0])
    sys.exit(1)

tests = loadTests(sys.argv[1])

for index,test in enumerate(tests):
    solution = test.solve()
    print "Case #%d: %d"%(index+1,solution)


