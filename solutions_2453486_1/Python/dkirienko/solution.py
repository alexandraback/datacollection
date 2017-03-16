from copy import *
def check(A, c):
    A = deepcopy(A)
    for i in range(4):
        A[i] = A[i].replace("T", c)
    for i in range(4):
        if A[i][0] + A[i][1] + A[i][2] + A[i][3] == c * 4:
            return True
    for i in range(4):
        if A[0][i] + A[1][i] + A[2][i] + A[3][i] == c * 4:
            return True
    if A[0][0] + A[1][1] + A[2][2] + A[3][3] == c * 4 or A[0][3] + A[1][2] + A[2][1] + A[3][0] == c * 4:
        return True
    return False

def solve(num):
    A = [input() for i in range(4)]
    try:
        input()
    except:
        pass
    print("Case #", num, ": ", sep = "", end = "")
    if check(A, 'X'):
        print('X won')
    elif check(A, 'O'):
        print('O won')
    elif '.' in A[0] + A[1] + A[2] + A[3]:
        print('Game has not completed')
    else:
        print('Draw')

for i in range(1, int(input()) + 1):
    solve(i)

