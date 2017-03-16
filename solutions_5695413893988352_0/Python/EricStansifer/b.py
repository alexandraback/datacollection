# Python 3.2

from common import *

def first_bigger(x, y, first):
    n = len(x)

    for i in range(first + 1, n):
        if x[i] == -1:
            x[i] = 0
        if y[i] == -1:
            y[i] = 9

    i = first
    while i >= 0:
        if x[i] != -1 and y[i] != -1 and x[i] > y[i]:
            for j in range(0, i):
                if x[j] == -1:
                    if y[j] == -1:
                        x[j] = y[j] = 0
                    else:
                        x[j] = y[j]
                else:
                    y[j] = x[j]
            break
        elif x[i] == -1 and y[i] == -1:
            x[i] = 1
            y[i] = 0
        elif x[i] == -1:
            x[i] = (y[i] + 1) % 10
        elif y[i] == -1:
            y[i] = (x[i] + 9) % 10
        else:
            i -= 1

    return (concat(x), concat(y))

def digit(c):
    if c == '?':
        return -1
    else:
        return int(c)

def concat(a):
    return (''.join([str(c) for c in a]))

def pad(i, n):
    y = str(i)
    while len(y) < n:
        y = '0' + y
    return y

def consistent(x_, i):
    y = str(i)
    while len(y) < len(x_):
        y = '0' + y
    for j in range(len(y)):
        if x_[j] != '?' and x_[j] != y[j]:
            return False
    return True

def main(casenum):

    x_, y_ = readline().split()
    x = [digit(c) for c in x_]
    y = [digit(c) for c in y_]
    n = len(x)

    res = []

    first = None
    for i in range(n):
        if x[i] != -1 and y[i] != -1 and x[i] != y[i]:
            first = i
            break

    if first is None:
        for i in range(n):
            if x[i] == -1:
                if y[i] == -1:
                    x[i] = y[i] = 0
                else:
                    x[i] = y[i]
            else:
                y[i] = x[i]
        res = [(concat(x), concat(y))]
    else:
        a, b = first_bigger(x[:], y[:], first)
        res = [(a, b)]
        b, a = first_bigger(y[:], x[:], first)
        res.append((a, b))

    res.sort(key = lambda a : (abs(int(a[0]) - int(a[1])), int(a[0]), int(a[1])))
    a, b = res[0]

    if n < 4:
        res_ = []
        for i in range(10 ** n):
            if not consistent(x_, i):
                continue
            for j in range(10 ** n):
                if consistent(y_, j):
                    res_.append((pad(i, n), pad(j, n)))
        res_.sort(key = lambda a : (abs(int(a[0]) - int(a[1])), int(a[0]), int(a[1])))
        # print (len(res), len(res_))
        # if res_[0] != res[0]:
            # print ('Case', casenum, x_, y_, a, b, res_[0][0], res_[0][1])

    a, b = res_[0]

    writecase(casenum, a + ' ' + b)

run(main)
