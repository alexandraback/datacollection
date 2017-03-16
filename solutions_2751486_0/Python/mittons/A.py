import sys

inp = sys.stdin

T = int(inp.readline())

vowels = {'a','e','i','o','u'}

for testCase in xrange(1,T+1):
        string, n = inp.readline().split(" ")
        n = int(n)
        numStrings = 0
        startPoint = 0
        consec = 0
        isVow = [0]*len(string)
        for i in xrange(n):
            if string[i] not in vowels:
                isVow[i] = 1
                consec += 1
        if consec == n:
            numStrings += len(string)+1-n
            startPoint = 1

        for i in xrange(n,len(string)):
            consec -= isVow[i-n]
            if string[i] not in vowels:
                consec += 1
                isVow[i] = 1
            if consec == n:
                numStrings += (i-n+2-startPoint)*(len(string)-i)
                startPoint = i-n+2
        
        print "Case #{}: {}".format(testCase,numStrings)
