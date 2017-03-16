def solve(n, p):
    if p > 2**(n - 2):
        return
    result = []
    if p == 2**(n - 2):
        result.append('0' + '1' * (n - 1))
    else:
        row = bin(p)[2:] + '0'
        result.append('0' * (n - len(row)) + row)
    for i in range(1, n - 1):
        result.append('0' * (i + 1) + '1' * (n - i - 1))
    result.append('0' * n)
    return result

output = 'Case #{}: {}'
num_tests = int(input())
for i in range(num_tests):
    n, p = map(int, input().split())
    result = solve(n, p)
    if result is None:
        print(output.format(i + 1, 'IMPOSSIBLE'))
    else:
        print(output.format(i + 1, 'POSSIBLE'))
        for row in result:
            print(''.join(map(str, row)))
