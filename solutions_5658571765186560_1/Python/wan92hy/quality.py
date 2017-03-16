import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

bad = 'GABRIEL'
good = 'RICHARD'

def solve():
    [X, R, C] = [int(c) for c in input().split()]
    #print(X,R,C)
    if X == 2:
        if R%2==0 or C%2==0:
            return bad
        else:
            return good
    if X>6:
        return good
    if max(R, C)<X:
        return good
    if 2*min(R, C)<X:
        return good
    if R*C%X != 0:
        return good
    if 2*min(R, C) == X:
        return good

    return bad

for T in range(int(input())):
    print('Case #%d: %s' % (T+1, solve()))