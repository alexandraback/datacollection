import sys
#import pprint
def scan4(line):
    x = 0
    o = 0
    t = 0
    for i in range(4):
        if line[i] == 'X':
            x = x + 1
        elif line[i] == 'O':
            o = o + 1
        elif line[i] == 'T':
            t = t + 1
    # 1 -> X won 2 -> O won 0 -> Draw/not completed
    if (x == 4) or ((x == 3) and (t == 1)):
        return 1
    if (o == 4) or ((o == 3) and (t == 1)):
        return 2
    return 0

def work(data):
    d = _work(data)
    if d == 1:
        return "X won"
    if d == 2:
        return "O won"
    if d == 3:
        return "Draw"
    else:
        return "Game has not completed"

def _work(data):
    # scan rows
    dot = 0
    for i in range(4):
        data[i] = data[i].strip()
        d = scan4(data[i])
        if d != 0:
            return d
        col = [data[0][i],data[1][i],data[2][i],data[3][i]]
        d = scan4(col)
        if d != 0:
            return d
    diag1 = [data[0][0], data[1][1], data[2][2], data[3][3]]
    d = scan4(diag1)
    if d != 0:
        return d
    diag2 = [data[3][0], data[2][1], data[1][2], data[0][3]]
    d = scan4(diag2)
    if d != 0:
        return d
    for i in range(4):
        for j in range(4):
            if data[i][j] == '.':
                return 0
    return 3

if __name__=='__main__':
    #fin = sys.stdin
    fin = open('A-small-attempt0.in')
    line = fin.readline()
    t = int(line)
    #print t
    for i in range(t):
        lines = []
        for j in range(4):
            line = fin.readline()
            lines.append(line)
        fin.readline()
        #pprint.pprint(lines)
        print 'Case #%d: %s' %(i+1,work(lines))
    
    
