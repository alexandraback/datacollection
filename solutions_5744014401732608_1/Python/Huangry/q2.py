import math
with open ('B-large (4).in', 'r') as f:
    with open ('q2solution.txt', 'w') as solution:
        t = int(f.readline())
        for case in range(t):
            line = f.readline().split()
            B, M = int(line[0]), int(line[1])
            count = M
            answer = ''
            logM = math.log(M, 2)
            if  logM > B-2:
                solution.write('Case #' + str(case + 1) + ': ' + 'IMPOSSIBLE' + '\n')
            else:
                matrix = [[0 for col in range(B)] for row in range(B)]
                rounded = int(logM)
                for i in range(B-rounded-2, B):
                    for j in range(i, B):
                        matrix[i][j] = 1
                matrix[0][B-rounded-2] = 1
                count -= 2**rounded
                while count>0:
                    new_rounded = int(math.log(count, 2))
                    count -= 2**new_rounded
                    matrix[0][B-new_rounded-2] = 1
                for i in range(B):
                    matrix[i][i] = 0


                solution.write('Case #' + str(case+1) + ': ' + 'POSSIBLE' + '\n')
                for r in matrix:
                    line = ''
                    for c in r:
                        line+= str(c)
                    solution.write(line + '\n')


        solution.closed
    f.closed