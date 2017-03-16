import sys

def solve(game):
    not_done = any('.' in row for row in game)
    rows = list(game) + [''.join(z) for z in zip(*game)]
    rows += [
        game[0][0] + game[1][1] + game[2][2] + game[3][3],
        game[0][3] + game[1][2] + game[2][1] + game[3][0]
    ]
    to_check = []
    for row in rows:
        if 'T' in row:
            to_check.append(row.replace('T', 'X'))
            to_check.append(row.replace('T', 'O'))
        else:
            to_check.append(row)
    if 'XXXX' in to_check:
        return 'X won'
    elif 'OOOO' in to_check:
        return 'O won'
    elif not_done:
        return 'Game has not completed'
    return 'Draw'

def line():
    return sys.stdin.readline().rstrip()

for i in range(int(line())):
    game = []
    for _ in range(4):
        row = line()
        game.append(row)
    line()
    print('Case #{}: {}'.format(i + 1, solve(game)))
