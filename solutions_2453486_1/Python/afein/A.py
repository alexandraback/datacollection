from sys import stdin

def count_four(tic_str):
    x = 0
    o = 0
    empty = 0
    for j in range(0,4):
        if tic_str[j] == 'X':
            x += 1
        elif tic_str[j] == 'O':
            o += 1
        elif tic_str[j] == 'T':
            x += 1
            o += 1
        else:
            empty += 1
    return x, o, empty

def main():
    for case in range(1, int(stdin.readline()) + 1):
        grid = [ stdin.readline().strip() for i in range(0, 4)]
        stdin.readline()
        empty = 0
        outp = ""
        for i in range(0,4):
            row_x, row_o, t = count_four(grid[i])
            empty += t
            col_x, col_o, t = count_four( \
                                    ''.join([grid[j][i] for j in range(0,4)]))
            empty += t

            if row_x == 4 or col_x == 4:
                outp = "X won"
            elif row_o  == 4 or col_o == 4:
                outp = "O won"
        diag1 = ''.join([grid[i][i] for i in range(0,4)])
        diag_x1, diag_o1, t = count_four(diag1)
        diag2 = ''.join([grid[3-i][i] for i in range(0,4)])
        diag_x2, diag_o2, t = count_four(diag2)
        if diag_x1 == 4 or diag_x2 == 4:
            outp = "X won"
        elif diag_o1 == 4 or diag_o2 == 4:
            outp = "O won"

        if outp == "":
            if empty == 0:
                outp = "Draw"
            else:
                outp = "Game has not completed"
        print "Case #" + str(case) + ": " + outp

if __name__=="__main__":
    main()
