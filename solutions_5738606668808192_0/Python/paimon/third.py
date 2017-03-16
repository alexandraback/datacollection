def generate(size, n):
    result = [0]*size
    result[0], result[1], result[-2], result[-1] = [1]*4
    for i, c in enumerate(reversed(bin(n)[2:])):
        if c == '1':
            result[2*i + 2], result[2*i + 3] = 1, 1
    return ''.join(str(x) for x in reversed(result))
    
answer = 'Case #{}:'
n_tests = int(input())
for i in range(n_tests):
    size, num = map(int, input().split())
    print(answer.format(i + 1))
    for j in range(num):
        print(generate(size, j), ' '.join(str(i) for i in range(3, 12)))
