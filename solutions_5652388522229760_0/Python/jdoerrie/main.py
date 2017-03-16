def solve(N):
    if N == 0:
        return 'INSOMNIA'

    digits = set(str(N))
    M = N

    while len(digits) < 10:
        M += N
        digits |= set(str(M))

    return M


def main():
    T = int(input())
    for t in range(T):
        N = int(input())
        print("Case #{}: {}".format(t + 1, solve(N)))

if __name__ == "__main__":
    main()
