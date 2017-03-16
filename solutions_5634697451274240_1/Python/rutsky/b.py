def solve(S):
    S = S[::-1]
    to_flip = '-'
    res = 0

    for c in S:
        if c == to_flip:
            res += 1
            to_flip = '-' if to_flip == '+' else '+'

    return res

if False:
    assert solve("+") == 0
    assert solve("++") == 0
    assert solve("-") == 1
    assert solve("--") == 1
    assert solve("-+") == 1
    assert solve("+-") == 2
    assert solve("--+-") == 3

else:
    T = int(input())

    for case_idx in range(T):
        S = input()

        print("Case #{}: {}".format(case_idx + 1, solve(S)))
