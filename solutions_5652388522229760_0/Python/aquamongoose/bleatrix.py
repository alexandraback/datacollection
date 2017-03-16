def solve(n):
    digs = set()
    cur = n
    while len(digs) != 10:
        tmp = cur
        while tmp > 0:
            digs.add(tmp%10)
            tmp //= 10
        cur += n
    return cur-n

t = int(input())
for i in range(t):
    print('Case #{}: '.format(i+1), end='')
    n = int(input())
    if n == 0:
        print('INSOMNIA')
    else:
        print(solve(n))
