import math

def solve(D, P):
    """ solve the problem """
    
    answer = max(P)
    if answer < 4: return answer

    for m in range(2, max(P)):
        special = 0
        for p in P:
            special += math.ceil(p/m) - 1
        if answer > special + m:
            answer = special + m

    return answer

def parse():
    """ parse input """
    D = int(input())
    P = [int(i) for i in input().split()]

    return D, P


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
