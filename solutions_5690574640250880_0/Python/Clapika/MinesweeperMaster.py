__author__ = 'Clapika'

fin = open('input', "r+")
fout = open('output', "w")


def count(matrix):
    count = 0
    for row in matrix:
        for cell in row:
            if cell != 0:
                count += 1
    return count


def expand(x, y):
    #print(x, y)

    matrix[x][y] += 1
    if count(matrix) == r * c - m:
        return True
    change = 0
    for k in [-1, 0, 1]:
        for j in [-1, 0, 1]:
            if 0 <= k + x < r and 0 <= j + y < c:
                if matrix[x + k][y + j] == 0:
                    change += 1
                matrix[x + k][y + j] += 1
    #print(matrix)
    if change != 0:
        for k in [-1, 0, 1]:
            for j in [-1, 0, 1]:
                if 0 <= k + x < r and 0 <= j + y < c:
                    #print("Matrix:", matrix)
                    #print("Check: ", k + x, j + y, matrix[x + k][y + j] == 1)
                    if matrix[x + k][y + j] == 1:
                        #print("Choose: ", k + x, j + y)
                        if expand(x + k, y + j):
                            return True
    matrix[x][y] -= 1
    for k in [-1, 0, 1]:
        for j in [-1, 0, 1]:
            if 0 <= k + x < r and 0 <= j + y < c:
                matrix[x + k][y + j] -= 1
    return False


n = int(fin.readline())
lines = [fin.readline().split() for x in range(n)]
for i in range(len(lines)):
    line = lines[i]
    r = int(line[0])
    c = int(line[1])
    m = int(line[2])
    matrix = [[0 for col in range(c)] for row in range(r)]
    fout.write("Case #%d:\n" % ((i + 1)))
    if expand(0, 0):
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if i == 0 and j == 0:
                    fout.write('c')
                elif matrix[i][j] != 0:
                    fout.write('.')
                else:
                    fout.write('*')
            fout.write('\n')
    else:
        fout.write('Impossible\n')





