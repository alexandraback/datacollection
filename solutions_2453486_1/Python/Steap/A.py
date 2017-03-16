#!/usr/bin/python

import sys

def solve(lines):
    empty = False
    for line in lines:
        x = 0
        o = 0
        for c in line:
            if c == 'X':
                x += 1
            elif c == 'O':
                o += 1
            elif c == 'T':
                x += 1
                o += 1
            else: # '.'
                empty = True
        if x == 4:
            return "X won"
        if o == 4:
            return "O won"
    # Draw or not over.
    if empty:
        return "Game has not completed"
    else:
        return "Draw"
        
def main():
    data = sys.stdin.readlines()
#    data.append("") # Hackety hack
    data.pop(0) # T  
    lines = []
    columns = ["", "", "", ""]
    diags = ["", ""]

    for lineno, line in enumerate(data):
        line = line.strip()
        if line == "":
            for i in range(0,4):
                diags[0] += lines[i][i]
                diags[1] += lines[i][3-i]
            
            res = solve(lines + columns + diags)
            print("Case #%d: %s" % (lineno/5+1, res))
            lines = []
            columns = ["", "", "", ""]
            diags = ["", ""]
        else:
            lines.append(line)
            for i, c in enumerate(line):
                columns[i] += c

if __name__ == '__main__':
    main()
