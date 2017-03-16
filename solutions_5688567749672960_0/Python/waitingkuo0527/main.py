def solve(N):
    """ solve the problem """

    A = [i for i in range(N+1)]

    for i in range(1, N+1):
        if i+1 <= N:
            A[i+1] = min(A[i]+1, A[i+1])
        s = [x for x in str(i)]
        s.reverse()
        reversed_i = int(''.join(s))
        if reversed_i <= N:
            A[reversed_i] = min(A[reversed_i], A[i]+1)


    return A[N]


def parse():
    """ parse input """

    N = int(input())

    return N


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
