T=int(input())
Len=[4,3,3,5,4,4,3,5,5,4]
for t in range(T):
    S=input()
    X=[0] * 10
    X[8] = S.count('G')
    X[0] = S.count('Z')
    X[2] = S.count('W')
    X[3] = S.count('H') - X[8]
    X[4] = S.count('R') - X[0] - X[3]
    X[6] = S.count('X')
    X[7] = S.count('S') - X[6]
    X[5] = S.count('F') - X[4]
    X[9] = S.count('I') - X[8] - X[6] - X[5]
    X[1] = S.count('O') - X[0] - X[2] - X[4]
    l = sum(X[i] * Len[i] for i in range(10))
    assert(l == len(S))
    res = ''.join(str(i) * X[i] for i in range(10))
    print("Case #%d: %s" % (t+1, res))
