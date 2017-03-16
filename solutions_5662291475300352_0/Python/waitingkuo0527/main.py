ANGLE = 0
NUM = 1
MINS = 2
def solve(N, groups):
    """ solve the problem """

    #print(N, groups)
    if N == 1: return 0

    p1 = [groups[0][ANGLE], 1, groups[0][MINS]]
    p2 = [groups[1][ANGLE], 1, groups[1][MINS]]

    if p1[MINS] == p2[MINS]: return 0

    p1t1 = p1[MINS] * (360 - p1[ANGLE])
    p1t2 = p1[MINS] * (720 - p1[ANGLE])
    p2t1 = p2[MINS] * (360 - p2[ANGLE])
    p2t2 = p2[MINS] * (720 - p2[ANGLE])

    if p1t2 <= p2t1 or p2t2 <= p1t1: return 1 


    return 0


def parse():
    """ parse input """
    N = int(input())
    groups = []
    for _ in range(N):
        groups.append([int(i) for i in input().split()])

    return N, groups


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
