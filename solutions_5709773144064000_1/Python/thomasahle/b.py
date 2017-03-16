import sys

def solve(C, F, X):
    head, f, best = 0, 2, X/2
    while head < best:
        head += C/f
        f += F
        best = min(best, head + X/f)
    return best

if __name__ == "__main__":
    read = lambda typ: list(map(typ,sys.stdin.readline().split()))
    T, = read(int)
    for t in range(T):
        C, F, X = read(float)
        print("Case #{}: {}".format(t+1, solve(C, F, X)))
