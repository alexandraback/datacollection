def intrl(fn):
    return [int(x) for x in fn.readline().strip().split()]

def xoro(row):
    X = sum([r == 'X' or r == 'T' for r in row]) == 4
    if X: return 'X'
    O = sum([r == 'O' or r == 'T' for r in row]) == 4
    if O: return 'O'
    return None

f = file('A.in','r')
T = intrl(f)[0]

for case in range(1,T+1):
    rect = [f.readline().strip() for i in range(4)]
    f.readline()
    bflag = False
    for j in range(4):
        w = xoro(rect[j])
        if w:
            print 'Case #%d: %s won' % (case,w)
            bflag = True
            break
        w = xoro([rect[i][j] for i in range(4)])
        if w:
            print 'Case #%d: %s won' % (case,w)
            bflag = True
            break
    if bflag: continue
    w = xoro([rect[i][i] for i in range(4)])
    if w:
        print 'Case #%d: %s won' % (case,w)
        continue
    w = xoro([rect[3-i][i] for i in range(4)])
    if w:
        print 'Case #%d: %s won' % (case,w)
        continue

    bflag = False
    for r in range(4):
        if bflag: break
        for c in range(4):
            if rect[r][c] == '.':
                print 'Case #%d: Game has not completed' % (case)
                bflag = True
                break
    if bflag: continue
    print 'Case #%d: Draw' % (case)
