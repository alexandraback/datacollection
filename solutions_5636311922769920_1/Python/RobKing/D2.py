def getstring(S):
    result = ""
    for i in range(len(S)):
        result += str(S[i])
        result += " "
    return result


def getnumber(A, base):
    result = 0
    for i in range(len(A))[::-1]:
        result += A[i] * (base ** (len(A) - i - 1))
    return result


def solve(T, K, C, S):
    if S * C < K:
        print "Case #%d: IMPOSSIBLE" % (T + 1)
    else:
        sample = []
        valid = False
        for i in range(S):
            if valid:
                break
            data = []
            for j in range(C):
                if (i * C + j) < K - 1:
                    data.append(i * C + j)
                else:
                    data.append(K - 1)
                    valid = True
            number = getnumber(data, K)
            sample.append(number + 1)
        print "Case #%d: %s" % (T + 1, getstring(sample))


cases = int(raw_input())

for T in xrange(cases):
    K, C, S = raw_input().split()
    K = int(K)
    C = int(C)
    S = int(S)
    solve(T, K, C, S)
