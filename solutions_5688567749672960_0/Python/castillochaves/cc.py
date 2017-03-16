def read(f):
    return int(f.readline())

def calc(data):
    N = data
    L = len(str(data))
    if L == 1:
        return N
    base_n = int("1"+"0"*(L-1))
    if N % 10 == 0:
        return 1 + calc(N-1)
    else:
        mod = int("1"+"0"*(L/2)+"0"*(L%2))
        result = int(str(N / mod)[::-1]) + N % mod
        base = calc(base_n)
        return base + min(N - base_n, result)

def write(solution):
    return str(solution)

def solve(f):
    data = read(f)
    solution = calc(data)
    return write(solution)

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as f:
        T = int(f.readline())
        for t in range(1, T+1):
            print('Case #{t}: {solution}'.format(t=t, solution=solve(f)))
