import sys

ab = "a b c d e f g h i j k l m n o p q r s t u v w x y z".split(" ")
input = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv z q"
output = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up q z"
present = []
map = {}
for i in range(len(input)):
    map[input[i]] = output[i]
    # if output[i] in ab:
    #     ab.remove(output[i])

# for k in sorted(map.keys()):
#     print k,"->",map[k]
# print "missing ",ab



class Test:
    
    def __init__(self, text):
        self.text = text

    def solve(self):
        solution = ""
        for c in self.text:
            solution += map[c]
        return solution


def loadTests(filename):
    tests = []

    f = open(filename)

    N = int(f.readline())
    for i in range(N):
        tests.append(Test(f.readline().strip()))
    return tests

if len(sys.argv) != 2:
    print "usage: %s datafile"%(sys.argv[0])
    sys.exit(1)

tests = loadTests(sys.argv[1])

for index,test in enumerate(tests):
    solution = test.solve()
    print "Case #%d: %s"%(index+1,solution)





