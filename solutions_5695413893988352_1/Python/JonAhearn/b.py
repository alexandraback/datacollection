def best(c, j):
    if '?' not in c and '?' not in j:
        return c,j
    for charno in range(len(c)):
        if '?' != c[charno] and '?' != j[charno]:
            if j[charno] > c[charno]:
                return c.replace('?', '9'), j.replace('?', '0')
            elif c[charno] > j[charno]:
                return c.replace('?','0'), j.replace('?', '9')
        elif '?' != c[charno]:
            c1, j1 = map(int,best(c, j.replace('?',str(min(9,int(c[charno])+1)),1)))
            c2, j2 = map(int,best(c, j.replace('?',str(max(0,int(c[charno])-1)),1)))
            c3, j3 = map(int,best(c, j.replace('?',c[charno],1)))
            cbest, jbest = c1, j1
            if abs(c2 - j2) < abs(cbest - jbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 < cbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 == cbest and j2 < jbest):
                cbest = c2
                jbest = j2
            if abs(c3 - j3) < abs(cbest - jbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 < cbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 == cbest and j3 < jbest):
                cbest = c3
                jbest = j3
            return str(cbest), str(jbest)
        elif '?' != j[charno]:
            c1, j1 = map(int,best(c.replace('?',str(min(9,int(j[charno])+1)),1), j))
            c2, j2 = map(int,best(c.replace('?',str(max(0,int(j[charno])-1)),1), j))
            c3, j3 = map(int,best(c.replace('?',j[charno],1), j))
            cbest, jbest = c1, j1
            if abs(c2 - j2) < abs(cbest - jbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 < cbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 == cbest and j2 < jbest):
                cbest = c2
                jbest = j2
            if abs(c3 - j3) < abs(cbest - jbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 < cbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 == cbest and j3 < jbest):
                cbest = c3
                jbest = j3
            return str(cbest), str(jbest)
        else:
            c1, j1 = map(int,best(c.replace('?','0',1),j.replace('?','0',1)))
            c2, j2 = map(int,best(c.replace('?','0',1),j.replace('?','1',1)))
            c3, j3 = map(int,best(c.replace('?','1',1),j.replace('?','0',1)))
            cbest, jbest = c1, j1
            if abs(c2 - j2) < abs(cbest - jbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 < cbest) or (abs(c2 - j2) == abs(cbest - jbest) and c2 == cbest and j2 < jbest):
                cbest = c2
                jbest = j2
            if abs(c3 - j3) < abs(cbest - jbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 < cbest) or (abs(c3 - j3) == abs(cbest - jbest) and c3 == cbest and j3 < jbest):
                cbest = c3
                jbest = j3
            return str(cbest), str(jbest)
    print('ERROR')

T = int(input())
for test in range(T):
    c,j = map(str, input().split())
    digits = len(c)
    bestc, bestj = best(c,j)
    print('Case #' + str(test+1) + ': ' + bestc.zfill(digits) + ' ' + bestj.zfill(digits))

    