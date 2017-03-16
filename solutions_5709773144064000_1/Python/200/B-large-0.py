from sys import stdin, stdout
from scipy import special

def time_cost(C, F, X, m):
    if m < 0:
        return X / 2
    tmp_cost = 0
    for n in xrange(m):
      tmp_cost += C / (2 + n * F)
    m_cost = tmp_cost + X / (2 + m * F)
    mm_cost = tmp_cost + C / (2 + m * F) + X / (2 + (m + 1) * F)
    return min(m_cost, mm_cost)

def derivative_of_time_cost(C, F, X, m):
    return C * special.polygamma(1, [m + 2 / F])[0] / F - F * X / (F * m + 2) ** 2

def binary_search(C, F, X, minNum, maxNum, positive):
    if minNum > maxNum:
        if positive:
            return (maxNum + 1, True)
        else:
            return (minNum - 1, False)
    midNum = int((minNum + maxNum) / 2)
    dcost = derivative_of_time_cost(C, F, X, midNum)
    #print '%f %f' % (midNum, dcost)
    if dcost > 0:
        return binary_search(C, F, X, minNum, midNum - 1, True)
    elif dcost < 0:
        return binary_search(C, F, X, midNum + 1, maxNum, False)
    else:
        return (midNum, positive)

T = int(stdin.readline())
for i in xrange(1, T + 1):
    args = stdin.readline().strip().split(' ')
    C = float(args[0])
    F = float(args[1])
    X = float(args[2])
    minFarm = 0
    maxFarm = int(X / C)
    last_cost = X / 2 + 1
    optFarm, positive = binary_search(C, F, X, minFarm, maxFarm, True)
    if positive and optFarm > 0:
        optFarm -= 1
    #print 'C=%.7f F=%.7f X=%.7f, m=%.7f' % (C, F, X, optFarm)
    #print optFarm
    last_cost = time_cost(C, F, X, optFarm)
    stdout.write('Case #%d: %.7f\n' % (i, last_cost))