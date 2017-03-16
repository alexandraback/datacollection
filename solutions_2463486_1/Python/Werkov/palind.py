#!/usr/bin/env python3
import sys

# generator of palindromes
def palind(N=999999):
    prev_l = 0
    stack = ['']

    for i in range(1,N+1):
        l = len(str(i))
        # empty the stack
        if l > prev_l:
            for n in stack:
                r = n[::-1]
                for m in range(10):
                    p = (n + str(m) + r)
                    yield p
            stack = []

        i = str(i)
        r = i[::-1]
        stack.append(i)
        p = (i + r)
        yield p
        prev_l = l


def unders(N):
    result = 0
    for p in palind():
        p = int(p)
        pp = p*p
        if pp > N:
            break
        pp = str(pp)
        if pp == pp[::-1]:
            result += 1
    return result

T = int(sys.stdin.readline().strip())

for t in range(T):
    A, B = sys.stdin.readline().strip().split()
    result = unders(int(B)) - unders(int(A) - 1)
    print("Case #{}: {}".format(t+1, result))
