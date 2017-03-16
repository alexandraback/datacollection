import sys
import math

T = int(sys.stdin.readline())

for case in range(1, T + 1) :
    output = "Case #" + str(case) + ": "
    line = sys.stdin.readline().strip().split(" ")
    A = int(line[0]) # already type
    B = int(line[1]) # total length

    P_A = sys.stdin.readline().strip().split(" ")
    P_A = [float(e) for e in P_A]

    def pAllCorrectBefore (pos):
        res = 1
        for _ in range(0, pos):
            res *= P_A[_]
            pass
        return res
            
    # keep typing
    def retype ():
        return 2 + B;

    minResult = retype()
    # press backspace to _
    for _ in range(0, A + 1):
        result = 0
        pCorrectBefore = pAllCorrectBefore(_)
        numberOfBack = A - _
        # print _, "numberOfBack", numberOfBack
        # print _, "pCorrectBefore", pCorrectBefore
        result += (numberOfBack + numberOfBack + B - A + 1) * pCorrectBefore
        # print _, result
        result += (numberOfBack + numberOfBack + B - A + B + 2) * (1 - pCorrectBefore)
        # print _, result
        if result < minResult:
            minResult = result
        # print "minResult", minResult

    minResult = round(minResult, 6)
    minResult = "{0:.6f}".format(minResult)
    # minResult = ("{0:.6}".format(minResult) + "000000")
    # minResult = minResult[:minResult.pos(".") + 6]
    output += minResult
    print output

