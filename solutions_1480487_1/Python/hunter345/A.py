import sys


_in = sys.stdin
#_out = sys.stdout


T = int(_in.readline())

for ci in range(T):
    data = list(map(int,_in.readline().split()))
    N = data[0]
    J = data[1:]

    X = sum(J)
    total = X

    check = True

    NJ = N

    while check:

        check = False

        avg = (total+X)/NJ

        guar = 0

        for i in range(N):
            if J[i] > avg:
                guar = guar + J[i]
                J[i] = -1
                NJ = NJ - 1
                check = True

        total = total - guar

    print("Case #{}:".format(ci+1),end=' ')

    for i in range(N):
        if J[i]==-1:
            min_p=0
        else:
            min_p=(avg-J[i])/X

        print("{:f}".format(min_p*100),end=' ')

    print()
