
CHAR_D = 0
CHAR_O = 1
CHAR_X = 2
CHAR_T = 3

if __name__ == "__main__":
    f = open('1.in', 'r')
    o = open('1.out', 'w')

    T = int(f.readline().strip())

    for t in xrange(T):
        a = []
        res = 0
        has_empty_sq = False
        for l in xrange(4):
            line = f.readline().strip()
            row_res = CHAR_T
            for c in xrange(4):
                if line[c] == "O":
                    char = CHAR_O
                elif line[c] == "X":
                    char = CHAR_X
                elif line[c] == "T":
                    char = CHAR_T
                else:
                    char = CHAR_D
                    has_empty_sq = True
                a.append(char)
                row_res = row_res & char
            # check rows
            res = res | row_res
        # check columns
        for r in xrange(4):
            col_res = CHAR_T
            for c in range(r, 16, 4):
                col_res = col_res & a[c]
            res = res | col_res
        # check diagonals
        lr_diagonal_res = a[0] & a[5] & a[10] & a[15]
        res = res | lr_diagonal_res
        rl_diagonal_res = a[3] & a[6] & a[9] & a[12]
        res = res | rl_diagonal_res

        case = t + 1
        if res == CHAR_O:
            s = "Case #%s: O won\n" % case
        elif res == CHAR_X:
            s = "Case #%s: X won\n" % case
        elif has_empty_sq:
            s = "Case #%s: Game has not completed\n" % case
        else:
            s = "Case #%s: Draw\n" % case

        o.write(s)

        f.readline().strip()
