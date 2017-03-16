
def used_for(L, Jsum = None):
    if Jsum == None:
        Jsum = sum([l[0] for l in L])

    return [ (L[-1][0] - l[0])*1./Jsum for l in L ]


def solve(N, J):
    L = [(J[i], i) for i in range(N)]
    L.sort()
    res = [0 for i in range(N)]

    jsum = sum(J)*1.

    while L[-1][0] > 0:
        if sum(used_for(L, jsum)) >= 1 :
            res[L[-1][1]] = 0.0
            L.pop()
        else:
            break

    used = used_for(L, jsum)
    plus = (1.0 - sum(used)) / len(L)

    for i in range(len(L)):
        res[L[i][1]] = used[i] + plus

    return [str(res[i]*100) for i in range(N)]



n = int(raw_input())

for i in range(n):
    tab = map(int, raw_input().split(' '))
    print "Case #" + str(i+1) + ": " + " ".join(solve(tab[0], tab[1:]))


