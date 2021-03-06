input = open(file = "input", mode = 'r')
output = open(file = "output", mode = 'w')

def f():
    n, m = list(map(int, input.readline().rstrip().split()))
    A = []
    for i in range(n):
        A.append(list(map(int, input.readline().rstrip().split())))
    F = [[0] * m for i in range(n)]
    for i in range(n):
        for j in range(m):
            F[i][j] = int(A[i][j] == 2)
    for i in range(n):
        if A[i].count(2) == 0:
            for j in range(m):
                F[i][j] = 1
    for j in range(m):
        flag = 1
        for i in range(n):
            flag = flag and (A[i][j] != 2)
        if (flag):
            for i in range(n):
                F[i][j] = 1
    flag = 1
    for i in range(n):
        for j in range(m):
            flag = flag and (F[i][j] == 1)
    if flag:
        output.write("YES" + "\n")
    else:
        output.write("NO" + "\n")


t = int(input.readline().rstrip())
for i in range(t):
    output.write("Case #" + str(i + 1) + ": ")
    f()
