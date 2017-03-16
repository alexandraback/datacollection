import math
def solve2(C, F, X):
    if X <= C:
        return X / 2

    n = math.ceil((F * (X - C) / C - 2) / F)
    
    ttf = C * sum([1 / (2 + F * (i - 1)) for i in range(n, 0, -1)])
    tc = X / (2 + n * F)

    return ttf + tc

def solve(C, F, X):
    currentF = 2
    tc   = X / currentF     # time for cookies
    ttf  = 0                # total time for farms
    best_tt = tc            # best total time

    while True:
        ttnf = C / currentF # time to next farm
        ttf += ttnf
        currentF += F
        tc = X / currentF
        if tc + ttf > best_tt:
            break
        best_tt = ttf + tc

    return best_tt

def main():
    T = int(input())
    for i in range(1, T + 1):
        C, F, X = (float(s) for s in input().strip().split())
        result = '{:.7f}'.format(solve(C, F, X))
        print('Case #', i, ': ', result, sep='')

if __name__ == "__main__":
    main()
