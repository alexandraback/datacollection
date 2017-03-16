def extractDigits(num, S):
    dig = ''
    for i in range(len(S)-1, -1, -1):
        if S[i] != '?':
            dig = dig + S[i]
        else:
            dig = dig + str(num % 10)
            num //= 10
    return int(dig[::-1])

def genPossible(S):
    count = 0
    for s in S:
        if s == '?':
            count += 1
    res = []
    for i in range(10**count):
        d = extractDigits(i, S)
        res.append(d)
    return res

def solve(C, J):
    assert(len(C) == len(J))
    N = len(C)
    Ca = []
    Ja = []
    for i in range(len(C)):
        Ca.append(C[i])
        Ja.append(J[i])
    minDiff = float('inf')
    perm1 = genPossible(Ca)
    perm2 = genPossible(Ja)
    min1 = -1
    min2 = -1
    for p1 in perm1:
        for p2 in perm2:
            if abs(p1 - p2) < minDiff:
                minDiff = abs(p1 - p2)
                min1 = p1
                min2 = p2
    assert(min1 != -1)
    assert(min2 != -1)
    ans1 = str(min1)
    ans2 = str(min2)
    while len(ans1) < N:
        ans1 = '0' + ans1
    while len(ans2) < N:
        ans2 = '0' + ans2
    return (ans1, ans2)

T = int(input())
for c in range(1, T+1):
    C, J = input().split()
    res = solve(C, J)
    print('Case #' + str(c) + ': ' + res[0] + ' ' + res[1])
