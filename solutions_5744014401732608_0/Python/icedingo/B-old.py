T = int(input())

for t in range(1, T+1):
    B, M = map(int, input().split())

    out = []
    tot = 1
    for b in range(1, B):
        line = '0'*b

        left = M - tot
        tline = B - b - 1
        if tline > left:
            tot += left
            line += '1'*left
            line += '0'*(tline - left)
        else:
            tot += tline
            line += '1'*tline

        line += '1'
        out.append(line)

    out.append('0'*B)

    print('Case #{}: '.format(t), end='')
    if tot < M:
        print('IMPOSSIBLE')
    else:
        print('POSSIBLE')
        print('\n'.join(out))
