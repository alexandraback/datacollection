def count_digits(N):
    digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    m, done_count = 1, 0
    while (N > 0):
        ds = list(str(m * N))
        for d in ds:
            x = int(d)
            if digits[x] != -1:
                digits[x] = -1
                done_count += 1
        if done_count == 10:
            return m*N
        m += 1

    return 'INSOMNIA'

def main():
    T = int(input().strip())
    for t in range(T):
        N = int(input().strip())
        ans = count_digits(N)
        print('Case #{n}: {ans}'.format(n=t + 1, ans=ans))



if __name__ == '__main__':
    main()