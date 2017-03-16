def check(line):
    #print line
    res = None
    if 'X' not in line: # O won
        res = 'O won'
    elif 'O' not in line: # X won
        res = 'X won'

    return res
    
T = int(raw_input())

for n in range(T):
    lines = [ ]
    
    res = None
    not_completed = False
    # read rows
    for j in range(4):
        line = raw_input()
        lines.append(line)
    
    lines0 = lines[:]
    # append columns
    for j in range(4):
        line = [line[j] for line in lines0]
        lines.append(line)
    
    # append diagonal
    lines.append([lines0[i][i] for i in range(4)])
    lines.append([lines0[i][3-i] for i in range(4)])
        
    for line in lines:
        if '.' in line:
            not_completed = True
            continue
            
        res = check(line)
        if res:
            break
 
    if res:
        print 'Case #%d: %s' % (n+1, res)
    elif not_completed:
        print 'Case #%d: %s' % (n+1, 'Game has not completed')
    else:
        print 'Case #%d: %s' % (n+1, 'Draw')
    
    if n < T-1:
        raw_input()