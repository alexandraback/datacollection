from copy import copy

prod = [0 for i in range(7)]
R = 0
N = 0
M = 0
K = 0
ans_set = []

def judge(guess_set):
    global prod
    guess_set.sort()

    for k in range(K):
        tmp = prod[k]
        for i in range(N - 1, -1, -1):
            if tmp % guess_set[i] == 0:
                tmp /= guess_set[i]
        if tmp != 1:
            return False

    return True

def dfs(dep, guess_set):
    global M, K, ans_set
    
    if dep == N:
        if judge(guess_set):
            ans_set = copy(guess_set)
    else:    
        for i in range(2, M + 1):
            new_set = copy(guess_set)
            new_set.append(i)
            dfs(dep + 1, new_set)

    return

fi = open('C-small-1-attempt0.in', 'r')
fo = open('C.out', 'w')

fi.readline()
line = fi.readline().split()
R = int(line[0])
N = int(line[1])
M = int(line[2])
K = int(line[3])

fo.write('Case #1:\n')

for Ri in range(R):
    line = fi.readline().split()
    for i in range(K):
        prod[i] = int(line[i])
    ans_set = []
    dfs(0, [])
    ans = ""
    for i in range(N):
        ans += str(ans_set[i])
    fo.write(ans + '\n')

fi.close()
fo.close()
