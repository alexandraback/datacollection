import sys

sys.stdin = open('A-small-attempt0.in', 'r')
sys.stdout = open('A-small-attempt0.out', 'w')

for t in range(int(input())):

    a = list(map(int, list(input().split()[1])))

    s = 0
    ans = 0

    for i in range(len(a)):
        if i > s:
            ans = max(ans, ans + i - s)
            s = i
        s += a[i]

    print('Case #%d: %s' % (
        t + 1,
        ans
    ))

sys.stdin.close()
sys.stdout.close()