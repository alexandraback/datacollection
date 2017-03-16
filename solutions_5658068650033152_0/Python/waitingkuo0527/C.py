def solve(N, M, K):
    """ solve the problem """

    if K <= 4: 
        #print('K <= 4')
        return K
    if N <= 2: 
        #print('N <= 2')
        return K
    if M <= 2:
        #print('M <= 2')
        return K

    ans = (N + M) * 2 - 4

    #for short in range(1, N+1):
    #    for long in range(short, N+1, 2):
    #        if short == long:
    #            h_start = 1
    #        else:
    #            h_start = 3
#
#            for h in range(h_start, M+1):
#                if (short + long) * h >= K*2:
#                    tmp = 2*short + (h-2)*2
#                    if ans > tmp:
#                        print('found')
#                        print(short, long, h)
#                        ans = tmp

    #FIXME +1 + 2 + 3 + 3
    for short in range(1, N+1):
        for h in range(1, M+1):
            extra = h - 1
            if extra % 2 != 0: extra -= 1
            max_long = short + extra
            #print(short, long, h)
            for long in range(short, max_long+1, 2):
                #print(short, long, h)
                allow = int( ((short + long) * h) / 2 )
                stones = 2 * short + (h-2) * 2

                #print('[-]', short, long, h, allow, stones)

                if allow >= K:
                    #ans = min(stones, ans)
                    if stones < ans:
                        #print('[0]', short, long, h, allow, stones)
                        ans = stones
                elif allow + 1 >= K:
                    #ans = min(stones+1, ans)
                    if stones+1 < ans:
                        #print('[1]', short, long, h, allow+1, stones+1)
                        ans = stones+1

    return ans


def parse():
    """ parse input """

    N, M, K = map(int, input().split(' '))


    return N, M, K


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
