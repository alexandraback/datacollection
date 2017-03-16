def check_win(game, turn):
    replaced = [s.replace('T', turn) for s in game]
    #horizont
    for i in range(4):
        if replaced[i].count(turn) == 4:
            return True
    #vertical
    for j in range(4):
        s = ''
        for i in range(4):
            s += replaced[i][j]
        if s.count(turn) == 4:
            return True
    #main diagonal
    s = ''
    for i in range(4):
        s += replaced[i][i]
    if s.count(turn) == 4:
        return True
    #poboch diagonal
    s = ''
    for i in range(4):
        s += replaced[i][3 - i]
    if s.count(turn) == 4:
        return True
    return False


def check_draw(game):
    for i in range(4):
        if game[i].count('.') != 0:
            return False
    return True


def main():
    fin = open('input.in', 'r')
    fout = open('output.txt', 'w')

    n = int(fin.readline())
    for i in range(1, n + 1):
        game = [fin.readline() for j in range(4)]

        if check_win(game, 'O'):
            print('Case #{}: O won'.format(i), file=fout)
        elif check_win(game, 'X'):
            print('Case #{}: X won'.format(i), file=fout)
        elif check_draw(game):
            print('Case #{}: Draw'.format(i), file=fout)
        else:
            print('Case #{}: Game has not completed'.format(i), file=fout)

        #skip empty line
        fin.readline()

    fin.close()
    fout.close()

main()
