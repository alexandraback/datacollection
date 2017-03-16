import math

def solve(input_path, output_path):
    with open(input_path, 'r') as fin:
        with open(output_path, 'w') as fout: 
            num_cases = int(fin.readline())
            for i in xrange(num_cases):
                r, c, m = map(lambda s : int(s), fin.readline().strip().split(" "))
                answer = process(r, c, m)
                if answer == "Impossible":
                    print r, c, m, r*c-m
                fout.write("Case #" + str(i+1) + ":\n" + answer + "\n")

def process(r, c, m):
    if r == 1:
        return "".join(["c"] + ["." for i in xrange(r *c-m-1)] + ["*" for i in xrange(m)])
    if c == 1:
        return "\n".join(["c"] + ["." for i in xrange(r *c-m-1)] + ["*" for i in xrange(m)])
    nonmine = r*c-m
    if nonmine <= 1:
        grid = list("\n".join(["".join(["*" for i in xrange(c)]) for j in xrange(r)]))
        if nonmine == 1:
            grid[0] = "c"
        return "".join(grid)
    elif 1 < nonmine < 4:
        return "Impossible"
    else:
        col = -1
        row = -1
        for i in xrange(min(nonmine/2, c), 1, -1):
            if nonmine % i != 1 and int(math.ceil(nonmine/(i+0.0))) <= r:
                col = i
                break
        for i in xrange(min(nonmine/2, r), 1, -1):
            if nonmine % i != 1 and int(math.ceil(nonmine/(i+0.0))) <= c:
                row = i
                break
        if col < 0 and row < 0:
            if m <= (r-2) * (c-2):
                grid = list("\n".join(["".join(["." for i in xrange(c)]) for j in xrange(r)]))
                for i in xrange(m):
                    row_idx = r - 1 - i/(c-2)
                    col_idx = c - 1 - (i % (c-2))
                    grid[row_idx * (c+1) + col_idx] = "*"
                    if r == 4 and c == 4 and m == 3:
                        print i, row_idx, col_idx
                grid[0] = "c"
                return "".join(grid)
            return "Impossible"  
        grid = list("\n".join(["".join(["*" for i in xrange(c)]) for j in xrange(r)]))
        if col > 0:
            for i in xrange(nonmine):
                row_idx = i / col
                col_idx = i - row_idx * col
                grid[row_idx * (c+1) + col_idx] = "."
        else:
            for i in xrange(nonmine):
                col_idx = i / row
                row_idx = i - col_idx * r
                grid[row_idx * (c+1) + col_idx] = "."
        grid[0] = "c"
        return "".join(grid)

dir = "F:\\Sync\\Dropbox\\Coding\\CodeJam\\2014\\"
input_path = dir + "C-small-attempt2.in"
output_path = dir + "C-small.out"
solve(input_path, output_path)
