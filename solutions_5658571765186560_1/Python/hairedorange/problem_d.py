import sys


def isavailable(testcase):
    if testcase[0] > 7:
        return False
    elif testcase[0] > max(testcase[1], testcase[2]):
        return False
    elif testcase[1] * testcase[2] % testcase[0] != 0:
        return False
    elif (testcase[0] + 1) // 2 > min(testcase[1], testcase[2]):
        return False
    elif testcase[0] < 4:
        return True
    elif testcase[0] == 4:
        return min(testcase[1], testcase[2]) > 2
    elif testcase[0] == 5:
        if min(testcase[1], testcase[2]) == 3:
            return max(testcase[1], testcase[2]) > 5
        return True
    elif testcase[0] == 6:
        return min(testcase[1], testcase[2]) > 3
    


testcasenum = int(sys.stdin.readline())

testcases = []

for i in range(testcasenum):
    X, R, C = sys.stdin.readline().split()
    testcases.append((int(X), int(R), int(C)))

caseno = 1

for testcase in testcases:
    print "Case #" + str(caseno) + ":", "GABRIEL" if isavailable(testcase) else "RICHARD"
    caseno += 1
