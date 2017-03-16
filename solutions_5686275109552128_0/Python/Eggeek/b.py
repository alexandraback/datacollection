import sys


sys.stdin = open('test.txt', 'r')
sys.stdout = open('ans.txt', 'w')


def solve(p):
    ans = 1010
    for i in range(1, 1010):
        tmp = 0
        for each in p:
            tmp += each / i - 1
            if each % i:
                tmp += 1
        ans = min(ans, tmp+i)
    return ans


T = input()

for t in range(T):
    d = input()
    p = map(int, raw_input().split(' '))
    ans = solve(p)
    print 'Case #%d: %d' % (t+1, ans)
