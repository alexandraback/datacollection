def possible(lawn):
    # Get the maximum heights in each row or column
    row_max = [max(row) for row in lawn]
    col_max = [max([row[col_num] for row in lawn]) for col_num in range(len(lawn[0]))]
    # For each square, check if it could have been reached
    for row_num in range(len(lawn)):
        for col_num in range(len(lawn[row_num])):
            if (lawn[row_num][col_num] < row_max[row_num] and 
                    lawn[row_num][col_num] < col_max[col_num]):
                return "NO"
    # If we got this far then the layout is possible
    return "YES"


fin = open("input.txt", "r")
fout = open("output.txt", "w")

t = int(fin.readline())

for i in range(t):
    dimensions = list(map(int, fin.readline().split(" ")))
    lawn = []
    for row in range(dimensions[0]):
        lawn += [list(map(int, fin.readline().split(" ")))]
    fout.write("Case #" + str(i + 1) + ": " + possible(lawn) + "\n")

fin.close()
fout.close()
