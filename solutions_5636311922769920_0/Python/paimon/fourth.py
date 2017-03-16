def solve(size, complexity, budget):
    if budget * complexity < size:
        return 'IMPOSSIBLE'
    result = []
    mul = 0
    for i in range(size):
        if mul == 0:
            mul = size**(complexity - 1)
            result.append(0)
        result[-1] += i * mul
        mul //= size
    return ' '.join(str(i + 1) for i in result)

answer = 'Case #{}: {}'
n_tests = int(input())
for i in range(n_tests):
    size, complexity, budget = map(int, input().split())
    print(answer.format(i + 1, solve(size, complexity, budget)))
