import sys

def isrecycled(a,b):
    aa = "%d%d"%(a,a)
    bb = "%d%d"%(b,b)
    if len(aa) != len(bb):
        return False
    res = str(a) in bb #and str(b) in aa
    # print a," ",aa," ",b," ",bb," -> ",res
    return res


def permut(a):
    perm_a = []
    sa = str(a)
    for i in range(1,len(sa)):
        k = int(sa[i:]+sa[:i])

        if len(str(k)) == len(sa) and not k in perm_a:
            perm_a.append(k)
    return perm_a

perms = {}

class Test:

    def __init__(self, a,b):
        self.a = a
        self.b = b

    def solve(self):
        solution = 0
        processed = {}
        for m in range(self.a, self.b+1):
            if m in processed:
                continue
            processed[m] = 1
                        
            pe = permut(m)
            for p in pe:
                if not p in processed and p <= self.b and p >= self.a:
                    solution += 1

        return solution


def loadTests(filename):
    tests = []

    f = open(filename)

    N = int(f.readline())
    # if True:

    for i in range(N):
        l = map(int,f.readline().strip().split(" "))
        tests.append(Test(l[0],l[1]))
    return tests

if len(sys.argv) != 2:
    print "usage: %s datafile"%(sys.argv[0])
    sys.exit(1)

tests = loadTests(sys.argv[1])

for index,test in enumerate(tests):
    solution = test.solve()
    print "Case #%d: %d"%(index+1,solution)


