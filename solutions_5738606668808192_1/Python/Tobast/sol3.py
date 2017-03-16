def solveCase():
    N,J = [ int(x) for x in input().strip().split(' ') ]
    # We assume N is 1<<x
    period = N >> 1
    patterns = []
    
    def genPatterns(cur):
        if len(cur) == period-1:
            patterns.append(cur+'1')
        else:
            genPatterns(cur+'0')
            genPatterns(cur+'1')
    genPatterns('1')
    
    nums = [ x+x for x in patterns ][:J]

    proofPatt = ('0'*(period-1) + '1')*2
    proofs = [ int(proofPatt, base) for base in range(2,11) ]

    for num in nums:
        print(num,end=' ')
        for pr in proofs:
            print(pr,end=' ')
        print('')

T = int(input())
for c in range(T):
    print("Case #{}:".format(c+1))
    solveCase()
