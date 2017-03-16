def solve(n, w):
    b = 2 ** (n - 1) + 1
    for _ in range(w):
        while True:
            b += 2
            x = bin(b)[2:]
            D = [0] * 11
            for i in range(2, 11):
                for p in 2, 3, 5, 7:
                    if int(x, i) % p == 0:
                        D[i] = p
                        break
                if D[i] == 0:
                    break
            if 0 not in D[2:]:
                break
        print(x, ' '.join(map(str, D[2:])))


t = int(input())

for i in range(t):
    n, j = map(int, input().split())
    print('Case #1:')
    solve(n, j)
