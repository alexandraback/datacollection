import sys

sys.stdin = open('B-large.in', 'r')
sys.stdout = open('b-large.out', 'w')

for c in range(int(input())):

    (C, F, X) = map(float, input().split())
    f = 2
    t = 0
    ans = X / f
    while t < ans:
        t += C / f
        f += F
        ans = min(ans, X / f + t)

    print('Case #%d: %.7f' % (c + 1, ans))

sys.stdin.close()
sys.stdout.close()