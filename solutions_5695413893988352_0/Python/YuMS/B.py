ans = 10e19
bestC = 0
bestJ = 0

def clear():
    global ans
    ans = 10e19

def update(nowC, nowJ):
    global ans
    global bestC
    global bestJ
    now = abs(nowC - nowJ)
    if now < ans or now == ans and (nowC < bestC or nowJ < bestJ):
        ans = abs(nowC - nowJ)
        bestC = nowC
        bestJ = nowJ

def tryWithFill(C, J, k, nowC, nowJ, fillC, fillJ):
#     print(C, J, k, nowC, nowJ, fillC, fillJ)
    tempC = nowC * (10 ** (len(C) - k - 1)) + (0 if (k >= len(C) - 1) else int(C[k + 1:].replace('?', fillC)))
    tempJ = nowJ * (10 ** (len(C) - k - 1)) + (0 if (k >= len(C) - 1) else int(J[k + 1:].replace('?', fillJ)))
#     print(nowJ * (10 ** (len(C) - k - 1)))
#     print(tempC, tempJ)
    update(tempC, tempJ)

def solve(C, J):
#     C = C[::-1]
#     J = J[::-1]
    global bestC
    global bestJ
    possibles = []
    now = 0
    normal = True
    for i in range(len(C)):
        if C[i] == '?' and J[i] == '?':
            now *= 10
            tryWithFill(C, J, i, now, now + 1, '9', '0')
            tryWithFill(C, J, i, now + 1, now, '0', '9')
        elif C[i] == '?':
            now *= 10
            num = int(J[i])
            if num > 0:
                tryWithFill(C, J, i, now + num - 1, now + num, '9', '0')
            if num < 9:
                tryWithFill(C, J, i, now + num + 1, now + num, '0', '9')
            now += num
        elif J[i] == '?':
            now *= 10
            num = int(C[i])
            if num > 0:
                tryWithFill(C, J, i, now + num, now + num - 1, '0', '9')
            if num < 9:
                tryWithFill(C, J, i, now + num, now + num + 1, '9', '0')
            now += num
        else:
            now *= 10
            if int(C[i]) == int(J[i]):
                now += int(C[i])
                continue
            else:
                if int(C[i]) < int(J[i]):
                    tryWithFill(C, J, i, now + int(C[i]), now + int(J[i]), '9', '0')
                else:
                    tryWithFill(C, J, i, now + int(C[i]), now + int(J[i]), '0', '9')
                normal = False
                break
    if normal:
        tryWithFill(C, J, len(C) - 1, now, now, '0', '0')
    return str(bestC).zfill(len(C)) + ' ' + str(bestJ).zfill(len(C))

def main():
    T = input()
    for i in xrange(1, T + 1):
        C, J = raw_input().split()
        clear()
        print 'Case #{0}: {1}'.format(i, solve(C, J))

if __name__ == '__main__':
    main()
