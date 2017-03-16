
def f(n):

    if n == 0:
        return 'INSOMNIA'
    digits = set()
    i = 1
    while True:
        digits.update(set(str(i * n)))
        if len(digits) == 10:
            return i*n
        i += 1

n_cases = int(input())
for case in range(n_cases):
    N = int(input())
    res = f(N)
    print('Case #' + str(case + 1) + ':', res)
    
