fh = open("B-small-attempt0.in", "r")
fh2 = open("output.txt", "w")
testCases = fh.readline()

for testCase in xrange(int(testCases)):
    A, B, K = [int(s) for s in fh.readline().split()]

    count = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                count += 1
    ans = count
    fh2.write("Case #" + str(testCase + 1) + ": " + str(ans) + "\n")
    

fh.close()
fh2.close()
    
    
    
        
