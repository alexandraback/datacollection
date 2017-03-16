T = int(input())

for t in range(1, T+1):
    S = input()
    out = S[0]
    for c in S[1:]:
        if c < out[0]:
            out += c
        else:
            out = c + out

    print('Case #{}: {}'.format(t, out))
