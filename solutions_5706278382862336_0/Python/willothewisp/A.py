from fractions import gcd

def solve(P, Q):
    d = gcd(P, Q)
    P //= d
    Q //= d

    if 2**40 % Q != 0:
        return 'impossible'
    P *= 2**40 // Q
    g = 40
    while P > 1:
        g -= 1
        P //= 2
    return g

def main():
    T = int(input())
    for tc in range(T):
        P, Q = map(int, input().split('/'))
        print("Case #{}: {}".format(tc + 1, solve(P, Q)))

if __name__ == "__main__":
    main()
