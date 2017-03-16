import sys
sys.stdin = open('b1.in')
sys.stdout = open('b1.out', 'w')
T = input()
def calc(x, y):
    res = 1
    nn = x
    while x >= nn-y+1:
        res *= x
        x -=1
    while y >= 1:
        res /= y
        y-=1
    return res


def sol():
    n, x, y = map(int, raw_input().split())
    if x < 0:
        x = -x
    if (x + y)%2 == 1:
        return 0
    if n >= 15:
        shenyu = n-15
        a = 6
    elif n >= 6:
        shenyu = n-6
        a = 4
    else:
        shenyu = n-1
        a = 2
    if x+y<=a-2:
        return 1
    if x+y != a:
        return 0
    tot = 0
    bad = 0
    i = 0
    while i <= a and i <= shenyu:
        if shenyu -i <= a:
            if i <= y:
                bad += calc(shenyu, i)
            tot += calc(shenyu, i)
        i += 1
    return 1.*(tot-bad)/tot

for ca in range(1, T+1):
    res = sol()
    print 'Case #'+str(ca)+':', res
