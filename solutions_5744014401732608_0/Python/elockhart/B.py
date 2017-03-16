def readints():
    return [int(X) for X in input().split(' ')]

for C in range(int(input())):
    B, M = readints()
    if M > 2**(B-2):
        print("Case #{}: IMPOSSIBLE".format(1+C))
    else:
        print("Case #{}: POSSIBLE".format(1+C))
        b = list(bin(M)[2:])
        if len(b) < B-2: 
            b = ['0']*(B-2-len(b)) + b
        if M == 2**(B-2):
            b = ['0'] + (['1'] * (B-1))
        else:
            b = ['0'] + b + ['0']
        print(''.join(b))
        for X in range(B-2):
            c = ['0'] * (2+X) + ['1'] * (B-2-X)
            print(''.join(c))
        b = list(bin(M)[2:])
        print(''.join(['0']*B))

