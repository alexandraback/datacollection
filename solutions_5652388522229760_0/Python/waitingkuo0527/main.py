def solve(N):
    """ solve the problem """

    if N == 0: return 'INSOMNIA'

    seen = [ False for i in range(10) ]

    _N = N
    while True:
        for i in str(N):
            seen[int(i)] = True
        finished = True
        for s in seen:
            if not s: finished = False
        if finished: break
        N += _N

    return N


def parse():
    """ parse input """

    N = int(input())

    return [N]


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
