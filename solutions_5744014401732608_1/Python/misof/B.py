T = int( input() )
for tc in range(T):
    B, M = [ int(x) for x in input().split() ]
    if M > 2**(B-2):
        print('Case #{}: IMPOSSIBLE'.format(tc+1))
        continue
    print('Case #{}: POSSIBLE'.format(tc+1))
    A = [ [ 0 for y in range(B) ] for x in range(B) ]
    ways = [ 0 for b in range(B) ]
    ways[B-1] = 1
    for i in range(1,B-1):
        for j in range(i+1,B):
            A[i][j] = 1
        ways[i] = 2**(B-2-i)

    for i in range(1,B):
        if M >= ways[i]:
            M -= ways[i]
            A[0][i] = 1

    assert M == 0
    for row in A:
        print(''.join(str(x) for x in row))
