ln = int(input())

for i in range(ln):
    [K, C, S] = [int(x) for x in input().split()]
    print('Case #' + str(i+1) + ': ', end='')
    for j in range(K-1):
        print(str(1+K**(C-1)*j), end=' ')
    print(str(1 + K ** (C - 1) * K-1))
