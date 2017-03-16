with open('A-large.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

with open('output.txt', 'w') as f:
    X_wins = ('XXXX', 'TXXX', 'XTXX', 'XXTX', 'XXXT')
    O_wins = ('OOOO', 'TOOO', 'OTOO', 'OOTO', 'OOOT')
    for t in xrange(T):
        rows = input[:4]
        columns = [''.join(zip(*rows)[i]) for i in range(4)]
        diagonal = [''.join([rows[i][i] for i in range(4)]), ''.join([rows[i][3 - i] for i in range(4)])]
        conditions = rows + columns + diagonal
        if len(filter(lambda x: x in X_wins, conditions)) > 0:
            result = 'X won'
        elif len(filter(lambda x: x in O_wins, conditions)) > 0:
            result = 'O won'
        elif '.' in ''.join(conditions):
            result = 'Game has not completed'
        else:
            result = 'Draw'
        f.write('Case #%d: %s\n' % (t + 1, result))
        del input[:5]
