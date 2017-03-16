from sys import argv

_, inputFile, outputFile = argv

out = open(outputFile, "w")
with open(inputFile, "r") as f:
    t = int(f.readline())
    
    for case in xrange(t):
        s = f.readline()
        n = len(s)
        s = list(s)
        
        res = ""
        
        curr = n
        for i in xrange(n):
            # Find biggest character
            
            biggest = '0'
            index = -1
            for j in xrange(curr):
                if s[j] >= biggest:
                    biggest = s[j]
                    index = j
            
            if index == -1:
                break
            
            res += s[index]
            s[index] = '0'
            
            curr = index
        
        for i in xrange(n):
            if s[i] != '0':
                res += s[i]
            
        out.write("Case #{0}: {1}".format(case + 1, res))

