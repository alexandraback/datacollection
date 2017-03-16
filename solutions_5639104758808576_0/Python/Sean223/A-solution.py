__author__ = 'sean'

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'A-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'A-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


for case in range(numbCases):
    words = next(it).split(' ')
    s_max = int(words[0])
    values = str(words[1]).strip()

    num_invited = 0
    num_standing = 0
    for i in range(len(values)):
        s_i = int(values[i])
        if s_i == 0:
            continue
        if i <= num_standing:
            num_standing += s_i
        else:
            num_invited += i - num_standing
            num_standing += num_invited
            num_standing += s_i

    answer = num_invited

    output += "Case #{0}: {1}\n".format(str(case+1), str(answer))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)