def solve(S):
    """ solve the problem """

    result = ''
    for i, ch in enumerate(S):
        if i == 0:
            result += ch
        else:
            if ch >= result[0]:
                result = ch + result
            else:
                result = result + ch


    return result


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
