T = eval(input())

for caseNum in range(T):
    S = input()
    n = len(S)
    curProb = '-'
    p = 1
    count = 0
    while p <= n:
        while p <= n and S[-p] != curProb:
            p += 1
        if p > n:
            break
        while p <= n and S[-p] == curProb:
            p += 1
        count += 1
        if curProb == '-':
            curProb = '+'
        else:
            curProb = '-'
    print('Case #{}: {}'.format(caseNum + 1, count))
