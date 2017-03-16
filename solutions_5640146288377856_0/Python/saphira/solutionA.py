
def getInput(path):
    f = open(path)
    lines = f.readlines()
    f.close()
    return lines


def print_ouput():
    lines = getInput("inputA.txt")
    no_cases = int(lines[0].strip())
    case = 1
    while (case<=no_cases):
        row, col, width = [int(x) for x in lines[case].strip().split()]
        solution = get_solution(row, col, width)
        print "Case #{0}: {1}".format(case, solution)
        case += 1


def get_solution(row, col, width):
    each_row = col / width
    total_guesses = row * each_row
    #One more guess for one side
    if col % width != 0:
        total_guesses += 1
    #add the remaining length
    total_guesses += width - 1
    return total_guesses



print_ouput()

