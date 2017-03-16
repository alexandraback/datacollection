import sys

linenum = int(sys.stdin.readline())

testcases = []

for i in range(linenum):
    maxvalue, dataset = sys.stdin.readline().split()
    testcases.append((int(maxvalue), dataset))

caseno = 1

for testcase in testcases:
    stoodnum = 0
    needednum = 0
    for i in range(testcase[0]+1):
        if i > stoodnum:
            needednum += i - stoodnum
            stoodnum = i + int(testcase[1][i]) - 0
        else:
            stoodnum += int(testcase[1][i]) - 0
    print "Case #"+str(caseno)+":", needednum 
    caseno += 1
