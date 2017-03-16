from bisect import insort, bisect_left

def f(A, others):
    i = bisect_left(others, A)
    while i > 0 and others:
        for x in others[:i]:
            if x < A:
                A += x
            else:
                break
        others = others[i:]
        i = bisect_left(others, A)
    if len(others) > 0:
        if A-1 == 0:
            return min(1 + f(A, others[1:]), len(others))
        insort(others, A-1)
        return min(1 + f(A, others), len(others)-1)
    return 0

def solve(A, others):
    return f(A, sorted(others))

T = int(raw_input())
for case in range(1, T+1):
    A, N = map(int, raw_input().split())
    others = map(int, raw_input().split())
    print "Case #{}: {}".format(case, solve(A, others))
