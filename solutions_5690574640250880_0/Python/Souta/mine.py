fin = open('C-small-attempt1.in', 'r')
fout = open('out.txt', 'w')
t = int(fin.readline())
for casecount in range(1, t+1):
    r, c, m = map(int, fin.readline().split())
    result = [(['.'] * c) for i in range(r)]
    result[0][0] = 'c'
    possible = True
    if r == 1:
        for j in range(c - m, c):
            result[0][j] = '*'
    elif c == 1:
        for i in range(r - m, r):
            result[i][0] = '*'
    elif r == 2:
        if m == r * c  - 1:
            result[1][0] = '*'
            for i in range(0, 2):
                for j in range(1, c):
                    result[i][j] = '*'
        elif m % 2 == 0  and r * c - m > 2:
            for i in range(0, 2):
                for j in range(c - m // 2, c):
                    result[i][j] = '*'
        else:
            possible = False
    elif c == 2:
        if m == r * c - 1:
            result[0][1] = '*'
            for i in range(1, r):
                for j in range(0, 2):
                    result[i][j] = '*'
        elif m % 2 == 0 and r * c - m > 2:
            for i in range(r - m // 2, r):
                for j in range(0, 2):
                    result[i][j] = '*'
        else:
            possible = False
    else:
        tr = r
        tc = c
        isdone = False
        while tr > 3 or tc > 3:
            if tr <= tc:
                if m < tc - 1:
                    for j in range(tc - m, tc):
                        result[tr - 1][j] = '*'
                    isdone = True
                    break
                if m == tc - 1 and tr == tc:
                    for j in range(2, tc):
                        result[tr - 1][j] = '*'
                    result[tr - 2][tc - 1] = '*'
                    isdone  = True
                    break
                for i in range(0, tr):
                    result[i][tc - 1] = '*'
                tc = tc - 1
                m = m - tr
            else:
                if m < tr - 1:
                    for i in range(tr - m, tr):
                        result[i][tc - 1] = '*'
                    isdone = True
                    break
                for j in range(0, tc):
                    result[tr - 1][j] = '*'
                tr = tr - 1
                m = m - tc
        if not isdone:
            if m == 7 or m == 6 or m == 4 or m == 2:
                possible = False
            else:
                if m >= 1:
                    result[2][2] = '*'
                    if m >= 3:
                        result[2][1] = '*'
                        result[2][0] = '*'
                        if m >= 5:
                            result[1][2] = '*'
                            result[0][2] = '*'
                            if m == 8:
                                result[0][1] = '*'
                                result[1][0] = '*'
                                result[1][1] = '*'
    fout.write('Case #')
    fout.write(str(casecount))
    fout.write(':\n')
    if possible:
        for i in range(0, r):
            for j in range(0, c):
                fout.write(result[i][j])
            fout.write('\n')
    else:
        fout.write('Impossible\n')
fin.close()
fout.close()
                
            
