def intrl(fn):
    return [int(x) for x in fn.readline().strip().split()]

f = file('B.in','r')
T = intrl(f)[0]

for case in range(1,T+1):
    N,M = intrl(f)
    rect = [intrl(f) for i in range(N)]
    maxr = [max(row) for row in rect]
    maxc = [max([rect[row][col] for row in range(N)]) for col in range(M)]
    bflag = False
    for r in range(N):
        if bflag: break
        for c in range(M):
            if rect[r][c] < maxr[r] and rect[r][c] < maxc[c]:
                print 'Case #%d: NO' % case
                bflag = True
                break
    if not bflag:
        print 'Case #%d: YES' % case
