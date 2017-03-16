def read_table():
    table = []
    for i in range(4):
        line = raw_input()
        table.append(list(line[:4].upper()))
    return table

def winning_sequences():
    for i in range(4):
        yield [(i,k) for k in range(4)]
    for j in range(4):
        yield [(k,j) for k in range(4)]
    yield [(i,i) for i in range(4)]
    yield [(i,3-i) for i in range(4)]

def get_winner(table):
    for winner in ["X", "O"]:
        for win_seq in winning_sequences():
            s = "".join([table[elem[0]][elem[1]] for elem in win_seq]).replace("T", winner)
            if s == (winner * 4):
                return winner
    return ""

def is_game_cont_possible(table):
    for raw in table:
        if "." in raw:
            return True
    return False

def show_game_outcome(case_index, table):
    winner = get_winner(table)
    cont_possible = is_game_cont_possible(table)
    msg_prefix = "Case #%d: " % case_index
    if winner == "X":
        print msg_prefix + "X won"
    elif winner == "O":
        print msg_prefix + "O won"
    elif cont_possible:
        print msg_prefix + "Game has not completed"
    else:
        print msg_prefix + "Draw"
def main():
    test_cases_num = raw_input()
    for i in range(int(test_cases_num)):
        table = read_table()
        show_game_outcome(i+1, table)
        try:
            raw_input()
        except:
            pass


if __name__ == '__main__':
    main()
