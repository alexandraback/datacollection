T = int(input())
for t in range(1, T + 1):
    print('Case #%d: ' % t, end='')
    B, M = map(int, input().split())
    if 2 ** (B - 2) < M:
        print('IMPOSSIBLE')
        continue
    print('POSSIBLE')
    if 2 ** (B - 2) == M:
        print('0' + ('1' * (B - 1)))
    else:
        b = bin(M)[2:]
        print(('0' * (B - 1 - len(b))) + b + '0')
    for b in range(2, B+1):
        print(('0' * b) + ('1' * (B - b)))
