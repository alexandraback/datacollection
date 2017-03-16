limits = [0]
C = [[0 for x in range(21)] for y in range(21)]

def precompute():
    global limits
    n = 0
    value = 0
    while value <= 20:
        value = 2 * n * n + 3 * n + 1
        limits.append(value)
        n += 1
    print limits

    global C
    for i in range(len(C)):
        for j in range(len(C[0])):
            if i == 0 or j == 0 or j == i:
                C[i][j] = 1
            else:
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

def solve(line):
    print "=" * 20
    N, X, Y = (int(x) for x in line.split())
    row = (X + Y) / 2
    filled_rows = 0
    while limits[filled_rows + 1] <= N:
        filled_rows += 1
    if filled_rows < row:
        return 0
    if filled_rows > row:
        return 1
    print filled_rows, row
    remaining_diamonds = N - limits[filled_rows]
    needed_diamonds = Y + 1
    if X == 0:
        if remaining_diamonds == 2 * Y + 1:
            return 1
        else:
            return 0
    if remaining_diamonds - (limits[filled_rows + 1] - limits[filled_rows]) / 2 >= needed_diamonds:
        return 1
    print "rem: %d, needed: %d" % (remaining_diamonds, needed_diamonds)
    good = 0
    total = 0
    for gd in range(0, remaining_diamonds + 1):
        if remaining_diamonds - gd > (limits[filled_rows + 1] - limits[filled_rows]) / 2:
            continue
        if gd > (limits[filled_rows + 1] - limits[filled_rows]) / 2:
            continue
        total += C[remaining_diamonds][gd]
        if gd >= needed_diamonds:
            good += C[remaining_diamonds][gd]
    return float(good) / float(total)

precompute()
f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    result = solve(f.readline().strip())
    out.write("Case #%s: %s\n" % (test, result))
out.close()
