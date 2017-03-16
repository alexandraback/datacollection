import math

f = open('B-small-attempt1.in','r').readlines()
fout = open('B-small-attempt1.out','w')

test = int(f[0].strip())

line = 1


def ok(s):
    for i in range(len(s) - 1):
        if s[i] != s[i + 1]:
            return False
    return True


def frac(n):
    now = 1
    for i in range(1, n + 1):
        now = now * i
    return now

for t in range(test):
    n = int(f[line].strip())
    line += 1
    a = f[line].strip().split()
    line += 1

    for l in range(len(a)):
        s = a[l]
        for j in range(len(a[l]) - 1):
            if a[l][j] == a[l][j + 1]:
                s = s.replace(a[l][j] + a[l][j], a[l][j])
        a[l] = s

    for i in range(len(a)):
        if len(a[i]) == 1:
            for j in range(i + 1, len(a)):
                if len(a[j]) == 1:
                    if a[j] in a[i]:
                        a[i] = a[i] + a[j]
                        a[j] = ' '
    if ' ' in a: a.remove(' ')

    dd = [False for i in range(len(a))]
    res = 1
    i = 0
    now = 1
    found = True
    while (i < len(a) - 1):
        if a[i] != ' ':
            if ok(a[i]):
                res = res * frac(len(a[i]))
            ttt = True
            for j in range(i + 1, len(a)):
                if len(a[j]) >= 3:
                    s = a[j][1:-1]
                    if (a[i][0] in s) | (a[i][-1] in s):
                        found = False
                        break
                if a[j][0] == a[i][-1]:
                    a[j] = a[i] + a[j]
                    dd[j] = True
                    ttt = False
                    break
                if a[j][-1] == a[i][0]:
                    a[j] = a[j] + a[i]
                    dd[j] = True
                    ttt = False
                    break
            if ttt == True: now += 1
        if found == False:
            break
        
        i += 1

    
    if dd[len(a) - 1] == False:
        if (len(a)) > 1: now += 1
        if ok(a[-1]): res = res * frac(len(a[-1]))
    if found == False:
        res = 0
    else:
        res = res * frac(now)
    s = 'Case #' + str(t + 1) + ': '
    print >> fout, s + str(res % 10000000007)

fout.close()
