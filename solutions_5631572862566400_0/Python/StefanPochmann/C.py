def naive(N, F):
    def build(): #circle, i):
        nonlocal best
        bff = F[circle[-1]]
        if len(circle) > best and bff in (circle[-2], circle[0]):
            best = len(circle)
        if bff == circle[-2]:
            nexts = remain
        elif bff == circle[0]:
            nexts = remain if len(circle) == 2 else []
        elif bff in remain:
            nexts = [bff]
        else:
            nexts = []
        for x in nexts:
            circle.append(x)
            remain.remove(x)
            build()
            circle.pop()
            remain.add(x)
    best = 0
    for first in range(N):
        circle = [first, F[first]]
        remain = set(range(N)) - set(circle)
        build()
    return best

for x in range(1, int(input()) + 1):
    N = int(input())
    F = [int(i) - 1 for i in input().split()]
    print('Case #%d:' % x, naive(N, F))
