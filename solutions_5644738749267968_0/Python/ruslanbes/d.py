
def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = ' '.join( map(str, res) )
    outputLine = casestr+status
    fw.write(outputLine + "\n")


def testWar(N, K, n, pointsK):
    for i in xrange(pointsK):
        if N[i] > K[n - pointsK + i]:
            return False
    return True

def solveWar(N, K, n):
    # test normal War
    pointsK = n
    while not testWar(N, K, n, pointsK):
        pointsK -= 1
    pointsN = n - pointsK # normal War

    decPointsN = n
    while not testWar(K, N, n, decPointsN):
        decPointsN -= 1

    return (decPointsN, pointsN)


##################################
#name = 'd-practice'
name = 'd-small'
#name = 'd-large'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()

T = int( lines.pop(0) )
for t in xrange(T):
    n = int( lines.pop(0) )
    N = map( float, lines.pop(0).split(' ') )
    K = map( float, lines.pop(0).split(' ') )
    N.sort()
    K.sort()
    output(t, solveWar(N, K, n) )