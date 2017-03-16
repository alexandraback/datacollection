from math import floor
from math import ceil

def explode(s, c):
    t = []
    s += c;
    p = 0;
    for i in range(len(s)):
        if (s[i] == c or s[i] == "\n") and s[p:i] != "" and s[p:i] != "\n":
            t.append(s[p:i])
            p = i + 1
    return t

def drawGrid(a):
    s = ""
    for i in a:
        for v in i: s += str(v)
        s +="\n"
    s = s[:-1]
    return s

def solveCase(line):
    data = explode(line, " ")
    r = int(data[0])
    c = int(data[1])
    m = int(data[2])
    n = r * c - m
    grid = list(range(r))
    for i in range(r):
        grid[i] = list(range(c))
        for j in range(c): grid[i][j] = "*"

    if (n == 1):
        grid[0][0] = "c"
        return drawGrid(grid)
    elif (n >= 2 * c and (n % c != 1)):
        completerows = floor(n / c)
        for i in range(r-1, r-completerows-1, -1):
            for j in range(c): grid[i][j] = "."
        if n % c != 0:
            for j in range(n % c): grid[r-completerows-1][j] = "."
        grid[r-1][c-1] = "c"
        return drawGrid(grid)
    elif (n >= 2 * r and (n % r != 1)):
        completecols = floor(n / r)
        for i in range(c-1, c-completecols-1, -1):
            for j in range(r): grid[j][i] = "."
        if n % r != 0:
            for j in range(n % r): grid[j][c-completecols-1] = "."
        grid[r-1][c-1] = "c"
        return drawGrid(grid)
    else:
        for h in range(2, r+1):
            minw = max(ceil(n / h), 2)
            maxw = floor(n/2 - h + 2)
            if maxw >= minw and minw <= c:
                w = minw
                for i in range(h):
                    for j in range(w):
                        grid[r-i-1][c-j-1] = "."
                for i in range(h-2):
                    for j in range(w-2):
                        if (j+1 + (w-2)*i <= (h*w - n)):
                            grid[r-h+i][c-w+j] = "*"
                grid[r-1][c-1] = "c"
                return drawGrid(grid)
    return "Impossible"

def process(data):
    out = ""
    for i in range(1, len(data)):
        if i > 1: out += '\n'
        out += "Case #" + str(i) + ":\n"
        out += solveCase(data[i])
    return out

def main(fn):
    iFile = open(fn + ".in", "r")
    oFile = open(fn + ".out", "w")
    print("Files opened.")

    data = []
    while True:
        line = iFile.readline()
        if not line: break
        data.append(line)

    out = process(data)
    print("Calculations complete. Outputting to file.")
    oFile.writelines(out)
    print("Output complete.")
    iFile.close()
    oFile.close()
    print("Files closed.")

main("large")
