import sys

# sys.stdin = open('d.in', 'r')
# sys.stdin = open('D-small-attempt3.in', 'r')
# sys.stdout = open('D-small-attempt3.out', 'w')
sys.stdin = open('D-large.in', 'r')
sys.stdout = open('D-large.out', 'w')

# 1. 中间有洞
# X >= 7 肯定不行
# 2. 金箍棒撑破
# X > R 且 X > C 肯定不行
# 3. z 型撑破
#  (X + 1) / 2 > MIN( R, C ) 肯定不行
# 3. 数量整除
# 必须 R*C % X == 0
# 4. 数量枚举
#    1 一定可以
#    2 一定可以
#    3 | 最小2x3 | 一定可以
#    4 | 最小2x4 | 只要有一边是 2 就不行，其他都行
#    5 | 最小3x5 | 只要有一边是 3 就不行，其他都行
#    6 | 最小3x6 | 只要有一边是 3 就不行，其他都行


def test(X, R, C):

    if X >= 7:
        return False
    if X > R and X > C:
        return False
    if R * C % X != 0:
        return False
    if (X + 1) // 2 > min(R, C):
        return False
    if X < 3:
        return True
    if X == 3:
        return True
        return R % 2 == 0 or C % 2 == 0
    if X == 4:
        return min(R, C) > 2
    if X == 5:
        return min(R, C) > 3
    if X == 6:
        return min(R, C) > 3

    raise Exception('不可能走到这里')


def solve():

    for t in range(int(input())):

        X, R, C = map(int, input().split())

        print('Case #%d:' % (t + 1), 'GABRIEL' if test(X, R, C) else 'RICHARD')

solve()

sys.stdin.close()
sys.stdout.close()