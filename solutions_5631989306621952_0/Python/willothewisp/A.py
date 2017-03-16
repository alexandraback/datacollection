from collections import deque

def go(S):
    a = deque()
    for c in S:
        if a and a[0] <= c:
            a.appendleft(c)
        else:
            a.append(c)
    return ''.join(a)

T = int(input())
for tc in range(T):
    S = input()
    print("Case #{}: {}".format(tc+1, go(S)))