def solve(A, B, K):
    """ solve the problem """

    #print( A, B, K )
    
    count = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K: 
                #print(a, b)
                count += 1
    #print(count)
    #exit()


    return count


def parse():
    """ parse input """

    A, B, K = map(int, input().split(' '))

    return A, B, K


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
