def solve(n):
    if n == 0: return "INSOMNIA"
    digits = set()
    c = 0
    while len(digits) < 10:
        c += n
        digits |= set(str(c))
    return c

def check(l):
    res = None
    for n in l:
        N = yield res
        N = int(N)
        res = N % n == 0 and len(set(''.join(map(str, range(n, N+1, n))))) == 10
    yield res

def generate():
    import random
    l = [random.randint(1, 1000000) for i in range(100)]
    return '100\n'+'\n'.join(map(str, l))+'\n', check.__get__(l)

if __name__ == '__main__':
    for i in range(int(input())):
        print("Case #", i+1, ": ", solve(int(input())), sep='')
