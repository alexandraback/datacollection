def cal(begin, end, l):
    if not l:
        return 0
    x = l.index(max(l))
    m1 = min(begin + x * R, E)
    m2 = max(end - (len(l) - x - 1) * R, 0)
    f1 = cal(begin, m1 - R, l[:x])
    f2 = cal(m2 + R, end, l[x + 1:])
    return f1 + f2 + (m1 - m2) * l[x]

fin = open('B-small-attempt1.in', 'r') 
T = int(fin.readline().rstrip())
caseNo = 0
fout = open('B-small.out', 'w')
for i in range(T):
    l = fin.readline().rstrip().split()
    E, R, N = int(l[0]), int(l[1]), int(l[2])
    v = [int(x) for x in fin.readline().rstrip().split()]
    #print(E,R,N,v)
    if E <= R:
        res = sum(v) * E
    else:
        res = cal(E, 0, v)
    caseNo += 1
    fout.write('Case #' + str(caseNo) + ': ' + str(res)  + '\n')

fin.close()
fout.close()

