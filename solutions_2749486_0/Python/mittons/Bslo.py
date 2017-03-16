import sys

inp = sys.stdin

T = int(inp.readline())

for testCase in xrange(1,T+1):
    X, Y = map(lambda x: int(x), inp.readline().split(" "))
    wayString = ""
    if X != 0:
        if X > 0:
            wayString += "WE"*X
        elif X < 0:
            wayString += "EW"*(-X)
    if Y != 0:
        if Y > 0:
            wayString += "SN"*Y
        elif Y < 0:
            wayString += "NS"*(-Y)
    print "Case #{}: {}".format(testCase, wayString)

