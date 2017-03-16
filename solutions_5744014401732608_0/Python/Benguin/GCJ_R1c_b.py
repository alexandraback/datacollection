def sol(b,m):

    if m > int(pow(2,b-2)):
        return "IMPOSSIBLE"

    A = [[1 if i > j else 0 for i in range(0,b)] for j in range(0,b)]

    if m == int(pow(2,b-2)):
        A[0] = [0]+[1 for i in range(1,b)]
    else:
        A[0] = [0 for i in range(0,b)]
        s = "{0:b}".format(m)[::-1]
        for i, c in enumerate(list(s)):
            if c == '1':
                A[0][b-2-i] = 1
            else:
                A[0][b-2-i] = 0
    sol = "POSSIBLE\n"
    for i in range(0,b):
        for j in range(0,b):
            sol += str(A[i][j])
        if i != b-1:
            sol += "\n"

    print(sol)
    return sol
            



fIn = open('input.txt', 'r')
fOut = open('output.txt', 'w')
case = 0
for line in fIn:
    print(case)
    if case > 0:
        b = int(line.split(" ")[0])
        m = int(line.split(" ")[1])
        fOut.write("Case #"+str(case)+": "+sol(b,m)+"\n")
    case += 1