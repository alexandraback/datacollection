

import sys

T = int(sys.stdin.readline())

def intToSet(num, S):
    res = []
    for i in range(len(S)):
        if (1<<i & num) > 0:
            res.append(S[i])
    return res
def intToSum(num, S):
    res = 0
    for i in range(len(S)):
        if (1<<i & num) > 0:
            res += S[i]
    return res


for i in range(1,T+1):
    line = sys.stdin.readline().split(' ')
    line = map(int, line)

    N = line[0]
    S = line[1:]


    d = dict()

    res1 = 0
    res2 = 0

    for j in range(1,1<<len(S)):
        sm = intToSum(j,S)
        if not sm in d:
            d[sm]=j
        else:
            res1=j
            res2=d[sm]
            break



    print "Case #%d:" % (i)
    for n in intToSet(res2,S):
        print n,
    print
    for n in intToSet(res1,S):
        print n,
    print
