def solve(K, C, S):
    assert(K == S)
    return list(range(1, K + 1))


T = int(input())
for t in range(T):
    K, C, S = map(int, input().split())
    s = solve(K, C, S)
    print('Case #{}: {}'.format(t + 1, ' '.join(map(str, s))))
