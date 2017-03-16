input = open("c.in" , "r")
output = open("c.out" , "w")

def solve2(R, C, M):
    A = [["*" for x in range(C)] for y in range(R)]
    A[0][0] = 'c'
    t = R * C
    m = M
    e = t - m
    if t == 1:
        if m > 0:
            return "Impossible"
        else:
            return '\n'.join([''.join(x) for x in A])
    if R == 1 or C == 1:
        if e < 2:
            return "Impossible"
        else:
            if R == 1:
                for x in xrange(1, e):
                    A[0][x] = '.'
                return '\n'.join([''.join(x) for x in A])
            if C == 1:
                for x in xrange(1, e):
                    A[x][0] = '.'
                return '\n'.join([''.join(x) for x in A])


def solve(R, C, M):
    t = R * C
    m = M
    e = t - m
    A = [["*" for x in range(C)] for y in range(R)]
    A[0][0] = 'c'
    if e == 1:
        return A
    if R == 1 or C == 1:
        if e < 1:
            return ["Impossible"]
        for x in xrange(1, e):
            if R == 1:
                A[0][x] = '.'
            if C == 1:
                A[x][0] = '.'
        return A
    A[0][1] = '.'
    A[1][0] = '.'
    A[1][1] = '.'
    e -= 4
    if R == 2 or C == 2:
        if e < 0 or e % 2 != 0:
            return ["Impossible"]
        for x in range(2, e/2 + 2):
            if R == 2:
                A[0][x] = '.'
                A[1][x] = '.'
            if C == 2:
                A[x][0] = '.'
                A[x][1] = '.'
        return A
    if e in [1, 3] or e < 0:
        return ["Impossible"]
    if e >= 2:
        A[0][2] = '.'
        A[1][2] = '.'
        e -= 2
    if e >= 2:
        A[2][0] = '.'
        A[2][1] = '.'
        e -= 2
    if e % 2 != 0:
        A[2][2] = '.'
        e -= 1
    if e > 0:
        for x in range(3, min(e/2 + 3, R)):
            A[x][0] = '.'
            A[x][1] = '.'
            e -= 2
            if e == 0:
                break
    if e > 0:
        for x in range(3, min(e/2 + 3, C)):
            A[0][x] = '.'
            A[1][x] = '.'
            e -= 2
            if e == 0:
                break
    if A[2][2] == ".":
        A[2][2] = "*"
        e += 1
    for x in range(2, R):
        for y in range(2, C):
            if e > 0:
                A[x][y] = "."
                e -= 1
            else:
                break
        if e == 0:
            break    
    return A

T = int(input.readline())
for i in range(1, T + 1):
    R, C, M = map(int, input.readline().split(" "))
    A = solve(R, C, M)
    print "Case #" + str(i) + ": "
    print '\n'.join([''.join(x) for x in A])
    output.write("Case #" + str(i) + ":\n" + '\n'.join([''.join(x) for x in A]) + "\n")
input.close()
output.close()
