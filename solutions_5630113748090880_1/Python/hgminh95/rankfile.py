from sys import argv

_, inputFile, outputFile = argv

out = open(outputFile, "w")

from collections import defaultdict

with open(inputFile, "r") as f:
    test = int(f.readline())
    
    for case in xrange(test):
        n = int(f.readline())
        
        cnt = {}
        cnt = defaultdict(lambda: 0, cnt)
        
        for i in xrange(2 * n - 1):
            numbers = map(int, f.readline().split())
            
            for number in numbers:
                cnt[number] += 1
        
        res = []
        print cnt
        for key, value in cnt.iteritems():
            if value % 2 != 0:
                res += [key]
        
        res.sort()
        
        out.write("Case #{0}: ".format(case + 1))
        for value in res:
            out.write("{0} ".format(value))
        out.write("\n")
         
