from fractions import gcd

inputFileName = "test.in"
#inputFileName = "A-small-attempt0.in"
#inputFileName = "A-small-attempt1.in"
inputFileName = "A-small-attempt2.in"
#inputFileName = "A-small-attempt3.in"
#inputFileName = "A-large.in"
outputFileName = inputFileName[:-3] + ".out"

def solve0(N, x):
    if x == 0:
        return N
    if x == 1:
        return N + 1
    a = x / 2 + 1
    b = (x + 1) / 2
    r = []
    r11 = 1 + a + solve0(N - a, x - a)
    r12 = 1 + x - a + solve0(N - (x - a) - 1, a - 1)
    r.append(max(r11, r12))
    if b != a:
        r21 = 1 + b + solve0(N - b, x - b)
        r22 = 1 + x - b + solve0(N - (x - b) - 1, b - 1)
        r.append(max(r21, r22))
        #    r.append(1 + a + solve0(N, x - a))
    #    r.append(1 + x - a + solve0(N, a - 1))
    #    if b != a:
    #        r.append(1 + b + solve0(N, x - b))
    #        r.append(1 + x - b + solve0(N, b - 1))
    return min(r)


def calcSingleTest(f):
    line = f.readline()
    R = int(line.split()[0])
    C = int(line.split()[1])
    W = int(line.split()[2])
    print 'R = {0}, C = {1}, W = {2}'.format(R, C, W)
    if W == 1:
        return R * C
    s = C / W  * (R - 1)
    o1 = C % W
    r = []
    if C > 2 * W:
        s += C / W - 1

    if C == W:
        r.append(C)
    elif o1 != 0:
        r1 = solve0(W, o1)
        r.append(r1)
    else:
        r1 = solve0(W, W)
        r.append(r1)

    if C > 2 * W:
        r2 = solve0(W, W - 1) - 1
        r.append(r2)
    s += min(r)
    return s


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, res))




