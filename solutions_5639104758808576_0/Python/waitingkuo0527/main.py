def solve(Smax, S):
    """ solve the problem """

    friends = 0
    stands = 0
    for level, si in enumerate(S):
        if stands < level:
            friends += level - stands
            stands = level + si
        else:
            stands += si
            

    return  friends


def parse():
    """ parse input """

    Smax, S = input().split()
    Smax = int(Smax)
    S = [int(si) for si in S]

    return Smax, S


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
