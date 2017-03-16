from itertools import count

def count_steps(n):
    digits = set()
    if n == 0:
        return 'INSOMNIA'
    for i in count(1):
        digits.update(str(n*i))
        if len(digits) == 10:
            return n*i
    
answer = 'Case #{}: {}'
n_tests = int(input())
for i in range(n_tests):
    n = int(input())
    print(answer.format(i + 1, count_steps(n)))
