import sys

# sys.stdin = open('c.in', 'r')
sys.stdin = open('C-small-attempt8.in', 'r')
sys.stdout = open('C-small-attempt8.out', 'w')
# sys.stdin = open('C-large.in', 'r')
# sys.stdout = open('C-large.out', 'w')

# 1. 合成字符串求值得 -1
# 1.1. 由于是多个合成，而且是指数
# 1.1.1. 如果子串 eval 得 -1
#        必须有奇数个子串
# 1.1.2. 如果子串 eval 得 1
#        必然不行
# 1.1.3. 如果子串 eval 得 字母，无论正负
#        子串数必须只含有一个 2 因子（被 2 整除且不被 4 整除）
# 1.2. 于是，如果有多个子串（X 很大），可以归约
#      至少 X = X % 8 是没有问题的
#      因为任何串四次方肯定归 1，中间还找不到就没戏了
# 2. 合成字符串前缀求值可得 i，后缀求值可得 k，而且最短前后缀不相交
#    那么既然 X 可以归约，L 相当有限，直接蛮力即可


def multiply(a, b):
    s1, c1 = a
    s2, c2 = b
    s, c = s1 * s2, '1'
    if c1 == '1':
        c = c2
    elif c2 == '1':
        c = c1
    elif c1 == c2:
        s *= -1
        c = '1'
    elif c1 == 'i' and c2 == 'j':
        c = 'k'
    elif c1 == 'i' and c2 == 'k':
        s *= -1
        c = 'j'
    elif c1 == 'j' and c2 == 'k':
        c = 'i'
    elif c1 == 'j' and c2 == 'i':
        s *= -1
        c = 'k'
    elif c1 == 'k' and c2 == 'i':
        c = 'j'
    elif c1 == 'k' and c2 == 'j':
        s *= -1
        c = 'i'
    return s, c


def evaluate(S):
    # 从前往后
    x = (1, '1')
    for i in range(len(S)):
        x = multiply(x, (1, S[i]))
    return x


def solve():

    for t in range(int(input())):

        L, X = map(int, input().split())
        single = str(input())
        S = single * (X % 8 + (8 if X >= 8 else 0))

        # print(L,X)
        # print(S)

        # 从前往后
        p1 = None     # 找到的位置
        n1 = (1, '1')
        for i in range(len(S)):
            n1 = multiply(n1, (1, S[i]))
            # print("  FD: ", i, n1)
            if n1 == (1, 'i'):
                p1 = i
                break

        # 从后往前
        p2 = None
        n2 = (1, '1')
        for i in range(len(S)-1, -1, -1):
            n2 = multiply((1, S[i]), n2)
            # print("  BK: ", i, n2)
            if n2 == (1, 'k'):
                p2 = i
                break

        # print(repr(p1), repr(p2))

        val = evaluate(S)

        result = val == (-1, '1')

        # print(repr(val))

        # if val == (1, '1'):
        #     result = False
        # elif val == (-1, '1') and L % 2 != 1:
        #     result = False
        # elif not(L % 2 == 0 and L % 4 != 0):
        #     result = False

        result = result and \
            p1 is not None and \
            p2 is not None and \
            p1 < p2 - 1 + (X * L - len(S))

        print('Case #%d:' % (t + 1), ('YES' if result else 'NO'))

solve()

sys.stdin.close()
sys.stdout.close()