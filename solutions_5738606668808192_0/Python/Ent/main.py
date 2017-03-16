def isprime(n):
    if n == 2 or n == 3:
        return [True, 0]
    if n % 2 == 0:
        return [False, 2]
    if n % 3 == 0:
        return [False, 3]
    i = 5
    w = 2
    while i * i <= n:
        if n % i == 0:
            return [False, i]
        i += w
        w = 6 - w
    return [True, 0]


def baseX(n, base): # n is a int
    temp = list(str(n))
    l = list(range(len(temp)))[::-1]
    return sum([int(temp[i]) * base ** l[i] for i in range(len(temp))])

t = int(input())
[N, J] = [int(i) for i in input().split()]
print('Case #1:')
count = 0

begin = baseX(int('1'+'0'*(N-1)), 2)
end = baseX(int('1'*N), 2)
for x in range(begin+1, end+1, 2):
    num = int(bin(x)[2:])
    tmp = []
    for b in range(2, 11):
        tmp.append(isprime(baseX(num, b)))
    if [False]*9 == [u[0] for u in tmp]:
        print(str(num), end=' ')
        for q in range(8):
            print(str(tmp[q][1]), end=' ')
        print(str(tmp[8][1]))
        count += 1
        if count == J:
            break

