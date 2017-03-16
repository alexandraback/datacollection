__author__ = 'sean'

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'D-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'D-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


def can_gabe_win(x, r, c):
    if x >= 7:
        return False
    if not (r * c) % x == 0:
        return False

    if x <= 2:
        return True
    if x == 3:
        return r*c >= 6
    if x == 4:
        return r*c >= 12

    if x == 5 or x == 6:
        print("not implemented yet")
        return False


for case in range(numbCases):
    line = next(it).strip().split()
    gabe_wins = can_gabe_win(int(line[0]), int(line[1]), int(line[2]))

    if gabe_wins:
        answer = "GABRIEL"
    else:
        answer = "RICHARD"

    output += "Case #{0}: {1}\n".format(str(case+1), str(answer))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)