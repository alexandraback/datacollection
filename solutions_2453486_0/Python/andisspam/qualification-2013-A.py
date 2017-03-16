f_in = open('A-small-attempt0.in', 'r')
n = int(f_in.readline())
f_out = open('qualification-2013-A.out', 'w')

winner_to_text = {\
    0 : 'X won',
    1 : 'O won',
    2 : 'Draw',
    3 : 'Game has not completed'
    }

for i in range(n):
    rows = [f_in.readline().strip() for j in range(4)]
    f_in.readline()
    columns = [''.join([row[j] for row in rows]) for j in range(4)]
    diagonals = [''.join([rows[j][j] for j in range(4)]), ''.join([rows[3-j][j] for j in range(4)])]

    winner = -1
    for line in rows + columns + diagonals:
        if (line.count('X') + line.count('T')) == 4:
            winner = 0
        if (line.count('O') + line.count('T')) == 4:
            winner = 1

    if winner == -1:
        complete = ''.join(rows)
        if complete.count('.') > 0:
            winner = 3
        else:
            winner = 2

    f_out.write('Case #%i: %s\n' % (i+1, winner_to_text[winner]))
