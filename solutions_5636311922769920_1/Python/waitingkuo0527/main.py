def solve(K, C, S):
    """ solve the problem """

    if C == 1:
        if K > S: return 'IMPOSSIBLE'
        else: return ' '.join(str(i) for i in range(1, K+1))

    if 2*S < K: return 'IMPOSSIBLE' 

    q = []
    S = int(K / 2)

    for t in range(S):
        i = t*2+1
        j = i+1
        pos = 0
        for c in range(1, C): pos += K**c
        pos *= (i-1)
        pos += j
        q.append(pos)

    if K % 2 != 0:
        q.append(K ** C)

            
    return ' '.join(str(i) for i in q)


def parse():
    """ parse input """
    K, C, S = [int(i) for i in input().split()]

    return K, C, S


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
