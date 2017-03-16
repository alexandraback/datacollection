#!/usr/bin/env python3
T = int(input())

for case in range(1, T+1):
    print('Case #{}: '.format(case), end='')
    N = int(input())
    p1 = sorted(map(float, input().split()))
    p2 = sorted(map(float, input().split()))

    normal, cheating = 0, 0
    b = p2[::]
    for i in p1:
        for j in b:
            if j > i:
                b.remove(j)
                normal -= 1
                break
        normal += 1
    for i in p1:
        if i > p2[0]:
            cheating += 1
            p2.pop(0)
        else:
            p2.pop()
    print(cheating, normal)
