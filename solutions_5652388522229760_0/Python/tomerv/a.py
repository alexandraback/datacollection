
def digits(n):
    return set(str(n))

def solve(n):
    seen_digits = set()
    i = 1
    while True:
        seen_digits = seen_digits | digits(i*n)
        if len(seen_digits) == 10:
            break
        i += 1
    return n*i

t = int(input())
for i in range(t):
    n = int(input())
    if n == 0:
        print('Case #{}: INSOMNIA'.format(i+1))
    else:
        print('Case #{}: {}'.format(i+1, solve(n)))
