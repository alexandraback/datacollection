T = int(input())

for i in range(T):
    n = int(input())

    c = [0 for i in range(2505)]

    for j in range(2*n - 1):
        hs = input().split(' ')

        for k in hs:
            c[int(k)] += 1

    out = []
    for j in range(len(c)):
        if c[j] % 2 == 1:
            out.append(j)

    out.sort()

    print("Case #" + str(i + 1) + ": ", end = '')
    print(' '.join([str(o) for o in out]))
