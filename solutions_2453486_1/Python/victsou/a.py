import sys

c = int(raw_input())

for case in range(c):
    m = []
    for i in range(4):
        m.append(list(raw_input()))

    mt = zip(*m) 
    d1 = [m[i][i] for i in range(4)]
    d2 = [m[3 - i][i] for i in range(4)]

    map(m.extend, [mt, [d1], [d2]])
    
    points = False
    found = False
    res = ""

    for l in m:
        if l.count('.'):
            points = True

        if l.count('X') + l.count('T') == 4:
            found = True
            res = ": X won"
            break
        elif l.count('O') + l.count('T') == 4:
            found = True
            res = ": O won"
            break
    
    if not found:
        res = ": Draw" if not points else ": Game has not completed"

    print "Case #" + str(case + 1) + res

    if (case != c - 1):
        raw_input()
