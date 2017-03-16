from collections import Counter

def possible(v, m, c):
    total = 0
    for d in m:
        if d > v:
            break
        total += d*c
        if total >= v:
            break
    return total >= v

def solve(C, V, m):
    existingnum = len(m)
    v = 1
    count = 0
    while v <= V:
        count += 1
        if not possible(v, m, C):
            m.append(v)
            m.sort()
        total = 0
        for d in m:
            if d > v:
                break
            total += d*C
        v = total + 1
    return len(m) - existingnum


tcnum = int(input())

for tc in range(1, tcnum+1):
    C, _, V = map(int, input().split())
    m = list(map(int, input().split()))
    print("Case #{}: {}".format(tc, solve(C, V, m)))