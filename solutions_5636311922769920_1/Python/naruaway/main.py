def encode_index(C, K, index_start):
    k = index_start
    i = 0
    for c in range(C):
        i *= K
        i += k
        k += 1
        if k >= K:
            k = K - 1
    return i + 1

assert(encode_index(2, 4, 0) == 2)
assert(encode_index(2, 4, 2) == 12)

def solve(K, C):
    return [encode_index(C, K, i) for i in range(0, K, C)]


T = int(input())
for t in range(T):
    K, C, S = map(int, input().split())
    s = solve(K, C)
    if len(s) > S:
        s = 'IMPOSSIBLE'
    else:
        s = ' '.join(map(str, s))

    print('Case #{}: {}'.format(t + 1, s))

