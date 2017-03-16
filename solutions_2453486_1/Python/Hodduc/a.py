n = input()
for i in range(1, n+1):
    def process():
        x = [raw_input().strip() for i in range(5)]
        for i in range(4):
            flag = [1, 1]
            flag2 = [1, 1]
            for j in range(4):
                if x[i][j] not in ('X', 'T'):
                    flag[0] = 0
                if x[j][i] not in ('X', 'T'):
                    flag[1] = 0
                if x[i][j] not in ('O', 'T'):
                    flag2[0] = 0
                if x[j][i] not in ('O', 'T'):
                    flag2[1] = 0
            if flag[0] or flag[1]:
                return 'X won'
            if flag2[0] or flag2[1]:
                return 'O won'
        for diag in (((0,3),(1,2),(2,1),(3,0)), ((0,0), (1,1), (2,2), (3,3))):
            flag = [1, 1]
            flag2 = [1, 1]
            for i, j in diag:
                if x[i][j] not in ('X', 'T'):
                    flag[0] = 0
                if x[j][i] not in ('X', 'T'):
                    flag[1] = 0
                if x[i][j] not in ('O', 'T'):
                    flag2[0] = 0
                if x[j][i] not in ('O', 'T'):
                    flag2[1] = 0
            if flag[0] or flag[1]:
                return 'X won'
            if flag2[0] or flag2[1]:
                return 'O won'

        if '.' not in ''.join(x):
            return 'Draw'
        else:
            return 'Game has not completed'
    print "Case #%d:" % i, process()
