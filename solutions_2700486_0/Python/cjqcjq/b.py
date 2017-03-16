import sys

def abs(x):
    if x < 0:
        return -x
    return x

def total(level):
    return level * (2 * level - 1)

def sum_c(y, n):
    if y > n:
        return 0
    c = 1
    for i in range(1, y + 1):
        c = c * (n - i + 1) / i
    ret = c
    for i in range(y + 1, n + 1):
        c = c * (n - i + 1) / i
        ret += c
    return ret

def divide(a, b):
    ret = 0.0
    for i in range(1, 10):
        d = a * 10 / b
        if d > 0:
            ret += 1.0 * d / pow(10, i)
            a = a * 10 - b * d
    return ret

def get_prob(n, x, y):
    level = (abs(x) + abs(y)) / 2 + 1
    if total(level) <= n:
        return 1.0
    elif total(level - 1) >= n:
        return 0.0
    else:
        if x == 0:
            return 0.0
        n -= total(level - 1)
        a = sum_c(y + 1, n)
        b = pow(2, n)
        return divide(a, b)

def solve(f):
    cas = open(f, 'r').readlines()
    for ic in range(1, len(cas)):
        [n, x, y] = cas[ic][0:-1].split(' ')
        n = int(n)
        x = int(x)
        y = int(y)
        ans = get_prob(n, x, y)
        res = 'Case #' + str(ic) + ': ' + str(ans)
        print res
solve(sys.argv[1])
