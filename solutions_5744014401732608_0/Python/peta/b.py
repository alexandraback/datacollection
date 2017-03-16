import sys, copy

def print_mat(m):
    for line in m:
        print("".join([str(x) for x in line]))

def add_to_mat(oldm, a):
    m = copy.deepcopy(oldm)
    for j in range(len(m)):
        m[j].append(0)
        if j == 1: m[j][-1] = 1
    m.append([0 for x in range(len(m)+1)])
    m[-1][0] = 1
    bina = bin(a)[2:].zfill(len(m)-3)
    for j in range(len(bina)):
        if bina[j] == '1':
            m[-1][-j-2] = 1
    return m

def move_b(oldm):
    m = [[0 for x in range(len(oldm))] for y in range(len(oldm))]
    for i in range(len(m)-1):
        for j in range(len(m)-1):
            m[i][j] = oldm[i+1][j+1]
        m[i][-1] = oldm[i+1][0]
        m[-1][i] = oldm[0][i+1]
    m[-1][-1] = oldm[0][0]
    return m

def fill_mat(oldm, length):
    m = copy.deepcopy(oldm)
    for i in range(len(m)):
        for j in range(len(m), length):
            m[i].append(0)
    for i in range(len(m), length):
        m.append([0 for x in range(length)])
    return m

ans = [0, 0, 1, 2, 4, 8]
while ans[-1] < 10**18:
    ans.append(2*ans[-1])

mat = [None, None, [[0, 0], [1, 0]], [[0, 0, 0], [1, 0, 1], [1, 0, 0]]]
for i in range(4, len(ans)):
    m = copy.deepcopy(mat[i-1])
    for j in range(len(m)):
        m[j].append(0)
        if j == 1: m[j][-1] = 1
    m.append([0 for x in range(len(m)+1)])
    for j in range(len(m)):
        if j != 1 and j != len(m)-1: m[-1][j] = 1
    mat.append(m)
#for i in range(2, 10): print_mat(mat[i])
    
#print_mat(move_b(add_to_mat(mat[5], 5)))
#print_mat(move_b(fill_mat(add_to_mat(mat[5], 5), 10)))
#print(len(ans), ans[-1], ans[6])

t = int(sys.stdin.readline())
for i in range(t):
    b, m = [int(x) for x in sys.stdin.readline().split()]
    possible = True
    if ans[b] < m:
        possible = False
    if possible:
        bb = b
        sol = None
        while ans[bb] >= m:
            if ans[bb] == m:
                sol = mat[bb]
                break
            else: bb -= 1
        if not sol:
            a = m - ans[bb] - 1
            sol = add_to_mat(mat[bb], a)
    print("Case #" + str(i+1) + ": ", end="")
    if not possible: print("IMPOSSIBLE")
    else:
        print("POSSIBLE")
        print_mat(move_b(fill_mat(sol, b)))
