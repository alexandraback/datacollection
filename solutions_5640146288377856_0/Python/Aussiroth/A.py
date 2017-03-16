infile = open("Asmall.txt", "r")
outfile = open("Asmallout.txt", "w")

def solve(row, col, width):
    if width==col:
        return width
    elif col<width*2:
        solution=width*2-col
        solution+=(col-solution)/2+1
        return solution
    else:
        return 1+solve(row, col-width, width)

tcase = int(infile.readline().rstrip())
for z in range(1, tcase+1):
    raw = infile.readline().rstrip().split()
    row, col, width = int(raw[0]), int(raw[1]), int(raw[2])
    solution=0
    if width==1:
        solution = row*col
    else:
        if col==width:
            solution = width
        elif col<width*2:
            solution=width*2-col
            solution+=int((col-solution)/2+1)
        else:
            solution=solve(row, col, width)
    solution = int(solution)
    outline = "Case #" + str(z) + ": " + str(solution)+"\n"
    outfile.write(outline)
    print(outline)

infile.close()
outfile.close()
