ANGLE = 0
NUM = 1
MINS = 2
def solve(N, groups):
    """ solve the problem """

    people = []
    if N == 1 and groups[0][NUM] == 1: return 0

    for g in groups:
        for t in range(g[NUM]):
            angle = g[ANGLE]
            mins = g[MINS] + t
            people.append([angle, 1, mins])

    count = 0
    is_continue = True
    while is_continue:
        #print(people)
        if len(people) == 1: break
        t1s = []
        t2s = []
        for p in people:
            t1 = (360 - p[ANGLE]) * p[MINS]
            t2 = (720 - p[ANGLE]) * p[MINS]
            t1s.append(t1)
            t2s.append(t2)
        slowest = max(t1s)
        slowest_index = t1s.index(slowest)

        is_found = False
        for i, p in enumerate(people):
            if i == slowest_index: continue
            if t2s[i] <= slowest:
                is_found += 1
                break

        if is_found:
            people.pop(slowest_index)
            count += 1
            
        if not is_found: break



    return count


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
