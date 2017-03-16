fi = open('B1.in', 'r')
fo = open('B.out', 'w')

tcase = int(fi.readline())
for icase in range(tcase):
    line = fi.readline().split()
    n = int(line[0])
    m = int(line[1])

    lawn = []
    
    for i in range(n):
        lawn.append([])
        line = fi.readline().split()
        for j in range(m):
            lawn[i].append(int(line[j]))

    no_ans = False
    for i in range(n):
        for j in range(m):
            hl = vl = False
            for k in range(n):
                if lawn[k][j] > lawn[i][j]:
                    vl = True
                    break
            for k in range(m):
                if lawn[i][k] > lawn[i][j]:
                    hl = True
                    break
            if hl and vl:
                no_ans = True
                break
        if no_ans:
            break

    if no_ans:
        ans_str = 'NO'
    else:
        ans_str = 'YES'

    fo.write('Case #%d: %s\n' % (icase + 1, ans_str))

fi.close()
fo.close()
