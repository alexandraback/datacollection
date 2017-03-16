def solve(stack):
    prev = '+'
    result = 0
    for c in reversed(stack):
        if c != prev:
            result += 1
        prev = c
    return result

answer = 'Case #{}: {}'
n_tests = int(input())
for i in range(n_tests):
    result = solve(input())
    print(answer.format(i + 1, result))
