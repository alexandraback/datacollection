def count_steps(n):
    digits = set()
    for i in range(1, 100):
        digits.update(str(n*i))
        if len(digits) == 10:
            return n*i
    return 'INSOMNIA'
    
answer = 'Case #{}: {}'
n_tests = int(input())
for i in range(n_tests):
    n = int(input())
    print(answer.format(i + 1, count_steps(n)))
