#!/usr/bin/python3
def solve(A, motes):
    while len(motes) > 0:
        if motes[-1] < A:
            A += motes.pop()
        else:
            break
    if len(motes) == 0:
        return 0
    ops1 = solve(A, motes[:-1]) + 1
    if A == 1: return ops1
    ops2 = 0
    while A <= motes[-1]:
        A += A - 1
        ops2 += 1
    ops2 += solve(A, motes)
    return min(ops1, ops2)

T = int(input())
for t in range(1, T+1):
    A, N = map(int, input().split())
    motes = list(map(int, input().split()))
    motes.sort()
    motes.reverse()
    print('Case #%d: %d' % (t, solve(A, motes)))
