def soluce(S):
    r = ''
    local_max = None
    for i, c in enumerate(S):
        if local_max is None or local_max <= c:
            r = c + r
            local_max = c
        else:
            r += c
    return r


T = int(input())
for i in range(T):
    S = input()
    print('Case #{}: {}'.format(i + 1, soluce(S)))
