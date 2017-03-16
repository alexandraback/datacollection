

def solveA(R, C, W) :
    if W == 1: return R*C   #must check all cells

    if C == W: return R + W - 1 #one per line + all cell in last line

    #eliminate row by row

    total_possible_per_line = C/W

    total_hits = (R - 1) * total_possible_per_line

    # first hits on remaining row : total_possible - 1
    fh = total_possible_per_line - 1
    total_hits += fh

    remaining_cells =  C - fh * W
    if remaining_cells == W :
        total_hits += W
    else :
        total_hits += W + 1

    return total_hits

def solve(in_filename, out_filename):
    with open(in_filename, 'r') as file, open(out_filename, 'w') as ofile :
        lines = file.readlines()
        T = int(lines[0].strip())

        for case in range(0, T) :
            tokens = lines[case + 1].split()
            R, C, W = int(tokens[0]), int(tokens[1]), int(tokens[2])
            sol = solveA(R, C, W)
            ofile.write("Case #%d: %d\n"%(case+1, sol))

if __name__ == '__main__':
    import sys
    import os
    _, input = sys.argv
    output = os.path.splitext(input)[0] + '.out'
    solve(input, output)