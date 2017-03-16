def _solve(S, sign):

    if len(S) == 1:
        if S[0] == sign: return 0
        else: return 1
    else:
        if S[-1] == sign:
            return _solve(S[:-1], sign)
        else:
            if sign == '+': sign = '-'
            else: sign = '+'
            return _solve(S[:-1], sign) + 1

def solve(S):
    """ solve the problem """

    return _solve(S, '+') 


def parse():
    """ parse input """
    S = input()

    return [S]


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
