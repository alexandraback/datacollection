dic = {(1, 1): 1, (1, 2): 2, (1, 3): 3, (1, 4): 4,
       (2, 1): 2, (2, 2): -1, (2, 3): 4, (2, 4): -3,
       (3, 1): 3, (3, 2): -4, (3, 3): -1, (3, 4): 2,
       (4, 1): 4, (4, 2): 3, (4, 3): -2, (4, 4): -1}

itoa = {1: '1', 2: 'i', 3: 'j', 4: 'k'}
atoi = {'1': 1, 'i': 2, 'j': 3, 'k': 4}


def mult(a, b):
    sig0, comp0 = a
    sig1, comp1 = b
    result = dic[(atoi[comp0], atoi[comp1])]
    sigRes = 1
    compRes = '1'
    if result > 0:
        sigRes = 1
        compRes = itoa[result]
    else:
        sigRes = -1
        compRes = itoa[-result]

    return (sig0 * sig1 * sigRes, compRes)

N = int(raw_input())
for j in range(N):
    length, times = [int(a) for a in raw_input().split()]
    cpy = raw_input()

    total = (1, '1')
    for c in cpy * (times % 4):
        total = mult(total, (1, c))

    result = total == (-1, '1')

    if result:
        S = cpy * (times % 4 + (4 if times >= 4 else 0))
        p1 = p2 = -1
        start = (1, '1')
        for i in range(len(S)):
            start = mult(start, (1, S[i]))
            if start == (1, 'i'):
                p1 = i
                break
        end = (1, '1')
        for i in range(len(S) - 1, -1, -1):
            end = mult((1, S[i]), end)
            if end == (1, 'k'):
                p2 = i
                break
        result = (p1 > -1 and p2 > -1) and p1 < p2 + \
            (times * length - len(S))

    print 'Case #' + str(j + 1) + ': ' + ('YES' if result else 'NO')
