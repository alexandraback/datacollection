FILE_PATH = 'C:\\codejam\\'
FILE_NAME = 'A-small-attempt1'

f = open(FILE_PATH + FILE_NAME + '.in', 'r')
o = open(FILE_PATH + FILE_NAME + '.out', 'w')

def case_result(case) :
    S = f.readline()
    if S[-1] == '\n' :
        S = S[:-1]

    L = [0]*26
    for s in S :
        L[ord(s) - ord('A')] += 1

    N = [0]*10
    # ZERO - Z
    x = L[ord('Z') - ord('A')]
    L[ord('Z') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    L[ord('R') - ord('A')] -= x
    L[ord('O') - ord('A')] -= x
    N[0] += x
    # TWO - W
    x = L[ord('W') - ord('A')]
    L[ord('T') - ord('A')] -= x
    L[ord('W') - ord('A')] -= x
    L[ord('O') - ord('A')] -= x
    N[2] += x
    #SIX - X
    x = L[ord('X') - ord('A')]
    L[ord('S') - ord('A')] -= x
    L[ord('I') - ord('A')] -= x
    L[ord('X') - ord('A')] -= x
    N[6] += x
    #EIGHT - G
    x = L[ord('G') - ord('A')]
    L[ord('E') - ord('A')] -= x
    L[ord('I') - ord('A')] -= x
    L[ord('G') - ord('A')] -= x
    L[ord('H') - ord('A')] -= x
    L[ord('T') - ord('A')] -= x
    N[8] += x
    #THREE - H
    x = L[ord('H') - ord('A')]
    L[ord('T') - ord('A')] -= x
    L[ord('H') - ord('A')] -= x
    L[ord('R') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    N[3] += x
    #FOUR - U
    x = L[ord('U') - ord('A')]
    L[ord('F') - ord('A')] -= x
    L[ord('O') - ord('A')] -= x
    L[ord('U') - ord('A')] -= x
    L[ord('R') - ord('A')] -= x
    N[4] += x
    #FIVE - F
    x = L[ord('F') - ord('A')]
    L[ord('F') - ord('A')] -= x
    L[ord('I') - ord('A')] -= x
    L[ord('V') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    N[5] += x
    #ONE - O
    x = L[ord('O') - ord('A')]
    L[ord('O') - ord('A')] -= x
    L[ord('N') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    N[1] += x
    #SEVEN - S
    x = L[ord('S') - ord('A')]
    L[ord('S') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    L[ord('V') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    L[ord('N') - ord('A')] -= x
    N[7] += x
    #NINE - N
    x = L[ord('I') - ord('A')]
    L[ord('N') - ord('A')] -= x
    L[ord('I') - ord('A')] -= x
    L[ord('N') - ord('A')] -= x
    L[ord('E') - ord('A')] -= x
    N[9] += x

    ans = ''
    for i in range(10) :
        ans += str(i) * N[i]
    return ans

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')
 
f.close()
o.close()
 