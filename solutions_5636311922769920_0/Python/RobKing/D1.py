def getstring(S):
    result = ""
    for i in range(S):
        result += str(i+1)
        result += " "
    return result


def solve(T, K, C, S):
    print "Case #%d: %s" % (T + 1, getstring(S))


cases = int(raw_input())

for T in xrange(cases):
    K, C, S = raw_input().split()
    K = int(K)
    C = int(C)
    S = int(S)
    solve(T, K, C, S)
