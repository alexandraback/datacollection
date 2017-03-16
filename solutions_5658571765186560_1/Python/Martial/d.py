import sys
sys.stdin = open('D-large.in')
sys.stdout = open('out.txt', 'w')

def solve(x,r,c):

    if r > c:
        r, c = c, r

    if r * c % x != 0:
        return 'RICHARD'

    if x == 1 or x == 2:
        return 'GABRIEL'

    if r==1:
        return 'RICHARD'

    if x==3:
        return 'GABRIEL'

    if x==4:
        if r==2:
            return 'RICHARD'
        else:
            return 'GABRIEL'

    if r==2:
        return 'RICHARD'

    if x==5:
        if r==3:
            if c==5:
                return 'RICHARD'
            else:
                return 'GABRIEL'
        return 'GABRIEL'

    if x==6:
        if r==3:
            return 'RICHARD'
        else:
            return 'GABRIEL'

    return 'RICHARD'

n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    X,R,C = list(map(int, list(input().split())))
    print('Case #{}: {}'.format(case+1, solve(X,R,C)))


