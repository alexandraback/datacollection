from random import randint


def solve_fractiles(K, C, S):
    res = []
    total = K**C
    part = int(total/K)
    for i in range(K):
        rng_min = part*i
        rng_max = part*(i + 1)
        r = randint(rng_min, rng_max - 1)
        res.append(r + 1)
    return ' '.join(str(r) for r in res)


def main():
    T = int(input().strip())
    for t in range(T):
        K, C, S = map(int, input().strip().split())
        ans = solve_fractiles(K, C, S)
        print('Case #{n}: {ans}'.format(n=t + 1, ans=ans))


if __name__ == '__main__':
    main()