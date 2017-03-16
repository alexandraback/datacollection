import sys

#test = True
test = False

##################################################
# for output
fout = open("%s.out" % (sys.argv[0]), "w")
WriteLineToFile = fout.write

# for input
if test: fin = open("%s.in.test" % (sys.argv[0]))
def ReadLineFromFile():
    global test
    if test:
        return fin.readline()
    else:
        return str(sys.stdin.readline()).strip()
##################################################

def start():
    global test

    t = int(ReadLineFromFile())
    for i in range(t):
        print i
        n = int(ReadLineFromFile())
        matrix = []
        matrix.append([0] * (n + 1))
        for j in range(n):
            line = map(int, ReadLineFromFile().split(' '))
            nc, cs = line[0], line[1:]
            #print nc, cs
            matrix.append([0] * (n + 1))
            for k in range(nc):
                matrix[j + 1][cs[k]] = 1
        WriteLineToFile("Case #%d: " % (i + 1))
        solve(n, matrix)
    fout.close()
    if test: fin.close()

def solve(n, matrix):
    chk_matrix = [False] * (n + 1)
    for i in range(1, n + 1):
        if sum(matrix[i]) >= 2:
            total = []
            visit(i, i, matrix, chk_matrix, total)
            for item in total:
                if total.count(item) >= 2:
                    WriteLineToFile("Yes\n")
                    return
    WriteLineToFile("No\n")
    return

def visit(start, n, matrix, chk_matrix, total):
    #print n, chk_matrix
    # should cut .....
    chk_matrix[n] = True
    vc = 0
    for i in range(1, len(chk_matrix)):
        if matrix[n][i] == 1 and chk_matrix[i] == False:
            vc += 1
            visit(start, i, matrix, chk_matrix, total)
    if vc == 0:
        total.append((start, n))
    chk_matrix[n] = False

if __name__ == '__main__':
    start()