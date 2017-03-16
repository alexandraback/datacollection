import argparse
from collections import defaultdict
def solve(board):
    '''
    Returns the solution 
    '''
    x_lens = defaultdict(lambda: (0,0,0,0))
    o_lens = defaultdict(lambda: (0,0,0,0))
    draw = True
    for y in range(4):
        for x in range(4):
            if board[y][x] == 'X':
                x_ul = x_lens[(y-1, x-1)][0] + 1
                x_u = x_lens[(y-1, x)][1] + 1
                x_ur = x_lens[(y-1, x+1)][2] + 1
                x_l = x_lens[(y, x-1)][3] + 1
                x_lens[(y,x)] = (x_ul, x_u, x_ur, x_l)
                o_lens[(y,x)] = (0,0,0,0)
            elif board[y][x] == 'O':
                o_ul = o_lens[(y-1, x-1)][0] + 1
                o_u = o_lens[(y-1, x)][1] + 1
                o_ur = o_lens[(y-1, x+1)][2] + 1
                o_l = o_lens[(y, x-1)][3] + 1
                o_lens[(y,x)] = (o_ul, o_u, o_ur, o_l)
                x_lens[(y,x)] = (0,0,0,0)
            elif board[y][x] == 'T':
                x_ul = x_lens[(y-1, x-1)][0] + 1
                x_u = x_lens[(y-1, x)][1] + 1
                x_ur = x_lens[(y-1, x+1)][2] + 1
                x_l = x_lens[(y, x-1)][3] + 1
                x_lens[(y,x)] = (x_ul, x_u, x_ur, x_l)

                o_ul = o_lens[(y-1, x-1)][0] + 1
                o_u = o_lens[(y-1, x)][1] + 1
                o_ur = o_lens[(y-1, x+1)][2] + 1
                o_l = o_lens[(y, x-1)][3] + 1
                o_lens[(y,x)] = (o_ul, o_u, o_ur, o_l)
            elif board[y][x] == '.':
                draw = False
                x_lens[(y,x)] = (0,0,0,0)
                o_lens[(y,x)] = (0,0,0,0)

            for m in x_lens[(y,x)]:
                if m >= 4:
                    return "X won"
            for n in o_lens[(y,x)]: 
                if n >= 4:
                    return "O won"
    if draw:
        return "Draw"
    else:
        return "Game has not completed"

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        T = int(inp.readline())
        for idx in range(1, T+1):
            board = []
            for x in range(4):
                board.append(inp.readline().strip())
            s = solve(board)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)
            inp.readline()
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
