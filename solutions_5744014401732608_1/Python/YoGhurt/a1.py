def solve(B, M, x, res):
    result = ""
    if M > pow(2, B - 2):
        result = "IMPOSSIBLE"
    else:
        result = "POSSIBLE"
    res.write("Case #{}: {}\n".format((x + 1), result))
    if result == "POSSIBLE":
        matrix = createMatrix(B, M)
        printMatrix(matrix, res)

def printMatrix(matrix, res):
    for x in range(len(matrix)):
        res.write(''.join(matrix[x]))
        res.write('\n')

def createMatrix(B, M):
    base = permRoutes(B)
    powers = '{0:b}'.format(M - 1)
    for x in range(B - len(powers) - 1):
        base[0][x] = "0"
    for x in range(len(powers)):
        base[0][B - 1 - len(powers) + x] = powers[x]
    base[0][B-1] = "1"
    return base

def permRoutes(B):
    matrix = []
    for x in range(B):
        matrix.append([])
        for y in range(B):
            val = "0"
            if x == 0 or x == B - 1:
                val = "0"
            else:
                if y > x:
                    val = "1"
            matrix[x].append(val)
    return matrix

def main():
    f = open("C://CodeJam/blarge.in", 'r')
    res = open("C://CodeJam/blarge.out", 'w')
    T = int(f.readline())
    print T
    for x in range(T):
        print x
        BM = f.readline()
        BM = BM.split()
        B = int(BM[0])
        M = int(BM[1])
        solve(B, M, x, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
