
def processCase(size, case):
    # each cell must be part of a row or column with only cells equal
    # or lesser in height than itself

    # calculate maximum value in each row and column
    row_max = []
    col_max = []
    for row in range(size[0]):
        row_max.append(0)
    for col in range(size[1]):
        col_max.append(0)
    
    for row in range(size[0]):
        for col in range(size[1]):
            value = case[row][col]
            if value > row_max[row]:
                row_max[row] = value
            if case[row][col] > col_max[col]:
                col_max[col] = value
            

    for row in range(size[0]):
        for col in range(size[1]):
            value = case[row][col]
            
            # check horizontal
            if row_max[row] <= value or col_max[col] <= value:
                continue
            else:
                return False

    return True

# open input file
in_file = open("in", "r")
n_cases = int(in_file.readline())

# open output file
out_file = open("out", "w")

for test_case in range(n_cases):
    size = in_file.readline().split()
    size = (int(size[0]), int(size[1]))

    case = []
    for line in range(size[0]):
        line = in_file.readline().split()
        for column in range(size[1]):
            line[column] = int(line[column])
        case.append(line)

    result = processCase(size, case)
    if result == True:
        result = "YES"
    else:
        result = "NO"
    out_file.write("Case #{}: {}\n".format(test_case + 1, result))
    
out_file.close()
in_file.close()
