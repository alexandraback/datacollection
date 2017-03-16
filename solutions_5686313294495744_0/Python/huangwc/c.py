import sys, random

sys.stdin = open('C-small-attempt0.in', 'r')
sys.stdout = open('C-small.out', 'w')

for t in range(1, int(input()) + 1):
    n = int(input())

    items = [input().strip().split() for i in range(n)]

    result = 0

    for k in range(10000):

        cnt = 0

        random.shuffle(items)
        sx = set()
        sy = set()
        for x, y in items:
            if x in sx and y in sy:
                cnt += 1
            sx.add(x)
            sy.add(y)

        result = max(result, cnt)

    print('Case #%s: %d' % (t, result))
