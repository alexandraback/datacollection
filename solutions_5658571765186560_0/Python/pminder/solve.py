#coding:utf8

def solve():
    X, R, C = [int(x) for x in input().split(' ')]

    if X == 1:
        return 'GABRIEL'

    if X == 2:
        if (R%2 == 0) or (C%2 == 0):
            return 'GABRIEL'
        else:
            return 'RICHARD'

    if X == 3:
        if R*C < 6:
            return 'RICHARD'
        elif (R%3 == 0) or (C%3 == 0):
                return 'GABRIEL'
        else:
            return 'RICHARD'

    if X == 4:
        if (R==4) and (C==4):
            return 'GABRIEL'
        if (min(R, C) == 3) and (max(R, C) == 4):
            return 'GABRIEL'
        return 'RICHARD'


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        r = solve()
        print("Case #{}: {}".format(i+1, r.upper()))
