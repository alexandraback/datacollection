def solve(R, C, W):
    """ solve the problem """

    #print(T, R, C)

    #for i in range(R):
    #    for j in range(C):
    #        if i == 
    if W == 1: return R*C

    type1 = 0
    remain = R
    while True:
        if remain < W: break
        remain -= W
        type1 += 1

    type2 = 0
    remain = C
    while True:
        #if r < W: break
        #r -= W
        #type2 += 1
        if remain >= 2*W:
            remain-=W
            type2 += 1
        else:
            if remain > W:
                type2 += W + 1
            else:
                type2 += W
            break

    ans = type1 * (R-1) + type2

    return ans


def parse():
    """ parse input """

    R, C, W = [int(i) for i in input().split()]

    return R, C, W


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
