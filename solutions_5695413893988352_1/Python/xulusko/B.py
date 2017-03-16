from sys import stdin

data = stdin.readlines()

for no, case in enumerate(data[1:], 1):
    C, J = case.split()

    CC, JJ = '', ''
    best = (10**20, str(10**20), str(10**20))
    def getBest(best, C, J):
        #print(best, C, J)
        cval, jval = int(C), int(J)
        val = (abs(cval-jval), C, J)
        if (best > val): return val
        return best

    for i, (c, j) in enumerate(zip(C, J), 1):
        if c == '?' and j == '?':
            best = getBest(best, CC + '0' + C[i:].replace('?', '9'), JJ + '1' + J[i:].replace('?', '0'))
            best = getBest(best, CC + '1' + C[i:].replace('?', '0'), JJ + '0' + J[i:].replace('?', '9'))
            CC += '0'
            JJ += '0'
        elif c == '?':
            if j > '0': best = getBest(best, CC + str(int(j)-1) + C[i:].replace('?', '9'), JJ + j + J[i:].replace('?', '0'))
            if j < '9': best = getBest(best, CC + str(int(j)+1) + C[i:].replace('?', '0'), JJ + j + J[i:].replace('?', '9'))
            CC += j
            JJ += j
        elif j == '?':
            if c > '0': best = getBest(best, CC + c + C[i:].replace('?', '0'), JJ + str(int(c)-1) + J[i:].replace('?', '9'))
            if c < '9': best = getBest(best, CC + c + C[i:].replace('?', '9'), JJ + str(int(c)+1) + J[i:].replace('?', '0'))
            CC += c
            JJ += c
        else:
            CC += c
            JJ += j
            if c > j:
                CC += C[i:].replace('?', '0')
                JJ += J[i:].replace('?', '9')
                break
            elif c < j:
                CC += C[i:].replace('?', '9')
                JJ += J[i:].replace('?', '0')
                break
    best = getBest(best, CC, JJ)
    print('Case #{}: {} {}'.format(no, best[1], best[2]))
