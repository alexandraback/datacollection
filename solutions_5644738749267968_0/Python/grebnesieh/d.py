input = open("d.in" , "r")
output = open("d.out" , "w")
T = int(input.readline())
for i in range(1, T + 1):
    N = int(input.readline())
    A = sorted(map(float, input.readline().split(" ")))
    B = sorted(map(float, input.readline().split(" ")))
    E = [0 for x in xrange(N)]
    a, b, c, y = 0, 0, 0, N
    while a < N and b < N:
        if A[a] < B[b]:
            E[b] += 1
            a += 1
        else:
            b += 1
    F = E[:]
    for x in xrange(N):
        if F[x] > 1:
            c += F[x] - 1
            F[x] = 1
        elif F[x] < 1:
            if c > 0:
                c -= 1
                F[x] = 1
    z = N - sum(F)
    while a < N and b < N:
        if A[a] < B[b]:
            E[b] += 1
            a += 1
        else:
            b += 1
    for x in A:
        if x < B[0]:
            y -= 1
            del B[-1]
        else:
            del B[0]
    print "Case #" + str(i) + ": " + str(y) + " " + str(z)
    output.write("Case #" + str(i) + ": " + str(y) + " " + str(z) + "\n")
input.close()
output.close()
