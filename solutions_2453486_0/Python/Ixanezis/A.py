import sys

games = [line.strip() for line in sys.stdin.readlines()[1:] if len(line) > 2]

goodO = set(['OOOT', 'OOTO', 'OTOO', 'TOOO', 'OOOO'])
goodX = set(t.replace('O', 'X') for t in goodO)

for i in xrange(len(games)/4):
    over = True
        
    states = games[i*4 : i*4+4]
    for line in states:
        over = over and ('.' not in line)

    for u in xrange(4):
        states.append(''.join(states[t][u] for t in xrange(4)))
    states.append(''.join(states[t][t] for t in xrange(4)))
    states.append(''.join(states[t][3-t] for t in xrange(4)))

    O = len(goodO & set(states)) > 0
    X = len(goodX & set(states)) > 0
    
    print 'Case #%d:' % (i+1),
    if O: print 'O won'
    elif X: print 'X won'
    elif over: print 'Draw'
    else: print 'Game has not completed'
    