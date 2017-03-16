FILE_PATH = 'C:\\codejam\\'
FILE_NAME = 'B-large'

f = open(FILE_PATH + FILE_NAME + '.in', 'r')
o = open(FILE_PATH + FILE_NAME + '.out', 'w')

def solve(C, J, large, index, N) :
    if index == N :
        c, j = ''.join(C), ''.join(J)
        return abs(int(c) - int(j)), c + ' ' + j

    c, j = C[index], J[index]
    l = large
    if c != '?' and j != '?' :
        if large == '' :
            if int(c) < int(j) :
                large = 'J'
            elif int(c) > int(j) :
                large = 'C'
        return solve(C[:], J[:], large, index+1, N)

    if large == 'C' :
        if c == '?' :
            C[index] = '0'
        if j == '?' :
            J[index] = '9'
        return solve(C[:], J[:], large, index+1, N)
    if large == 'J' :
        if c == '?' :
            C[index] = '9'
        if j == '?' :
            J[index] = '0'
        return solve(C[:], J[:], large, index+1, N)

    if c == '?' and j == '?' :
        if index == N-1 or (C[index+1] == '?' and J[index+1] == '?'):
            C[index] = J[index] = '0'
            return solve(C[:], J[:], large, index+1, N)

        C[index] = '0'
        J[index] = '0'
        ans1 =solve(C[:], J[:], large, index+1, N)

        C[index] = '0'
        J[index] = '1'
        large = 'J'
        ans2 = solve(C[:], J[:], large, index+1, N)
        C[index] = '1'
        J[index] = '0'
        large = 'C'
        ans3 = solve(C[:], J[:], large, index+1, N)
        C[index] = c
        J[index] = j
        large = l
        return min([ans1, ans2, ans3])

    if c == '?' :
        C[index] = J[index]
        ans = solve(C[:], J[:], large, index+1, N)
        C[index] = str(int(j) + 1) if j != '9' else '0'
        large = 'C' if j !='9' else 'J'
        ans = min(ans, solve(C[:], J[:], large, index+1, N))
        C[index] = str(int(j) - 1) if j != '0' else '9'
        large = 'J' if j !='0' else 'C'
        ans = min(ans, solve(C[:], J[:], large, index+1, N))
        C[index] = c
        J[index] = j
        large = l
        return ans
    if j == '?' :
        J[index] = C[index]
        ans = solve(C[:], J[:], large, index+1, N)
        J[index] = str(int(c) + 1) if c != '9' else '0'
        large = 'J' if c !='9' else 'C'
        ans = min(ans, solve(C[:], J[:], large, index+1, N))
        J[index] = str(int(c) - 1) if c != '0' else '9'
        large = 'C' if c !='0' else 'J'
        ans = min(ans, solve(C[:], J[:], large, index+1, N))
        C[index] = c
        J[index] = j
        large = l
        return ans
    return 'error'

def case_result(case) :
    S = f.readline()
    if S[-1] == '\n' :
        S = S[:-1]

    C, J = S.split()
    N = len(C)
    d, ans = solve(list(C), list(J), '', 0, N)

    return ans

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')
 
f.close()
o.close()
 