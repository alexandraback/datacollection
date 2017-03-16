import sys

sys.stdin = open('D-large.in', 'r')
sys.stdout = open('d-large.out', 'w')

for t in range(int(input())):

    N = int(input())
    A = sorted(map(float, input().split()))
    B = sorted(map(float, input().split()))

    x = 0
    _B = B.copy()
    for a in A:
        if a > _B[0]:
            _B.pop(0)
            x += 1
        else:
            _B.pop()

    y = 0
    _B = B.copy()
    for a in A:
        lose = False
        for i in range(len(_B)):
            if _B[i] >= a:
                lose = True
                _B.pop(i)
                break
        if not lose:
            y += 1
            _B.pop()

    print('Case #%d: %d %d' % (t + 1, x, y))

sys.stdin.close()
sys.stdout.close()