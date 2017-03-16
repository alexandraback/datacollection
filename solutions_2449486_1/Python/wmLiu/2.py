def transpose(l):
    t = []
    M, N = len(l), len(l[0])
    for i in range(N):
        t.append([l[k][i] for k in range(M)])
    return t
        
def elimate(lawn, m):
    flag = False
    i = 0
    while i < len(lawn):
        if max(lawn[i]) == m:
            flag = True
            lawn = lawn[:i] + lawn[i + 1:]
        else:
            i += 1
    return lawn, flag
    

def possible(lawn):
    while True:
        m = min([min(x) for x in lawn])
        lawn, flag1 = elimate(lawn, m)
        if len(lawn) == 0:
            return 'YES'
        lawn = transpose(lawn)
        lawn, flag2 = elimate(lawn, m)
        if len(lawn) == 0:
            return 'YES'
        if not flag1 and not flag2:
            return 'NO'
    return
    

fin = open('B-large.in', 'r') 
T = int(fin.readline().split()[0])
fout = open('B-large.out', 'w')
for caseNo in range(1, T + 1):
    N, M = [int(x) for x in fin.readline().rstrip().split()]
    lawn = [[int(x) for x in fin.readline().rstrip().split()] for j in range(N)]
    fout.write('Case #' + str(caseNo) + ': ' + possible(lawn) + '\n')

fin.close()
fout.close()

