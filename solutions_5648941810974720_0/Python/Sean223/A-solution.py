__author__ = 'sean'


# IN_FILE = 'test_input.txt'
# OUT_FILE = 'test_output.txt'

IN_FILE = 'A-small.in'
OUT_FILE = 'small_out.txt'

# IN_FILE = 'A-large.in'
# OUT_FILE = 'large_out.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""


for case in range(numbCases):
    answer = ""

    s = next(it).strip().lower()

    number_of_numbers = [0 for i in range(0, 10)]

    number_of_numbers[6] = s.count('x')
    for char in "six":
        s = s.replace(char, '', number_of_numbers[6])

    number_of_numbers[7] = s.count('s')
    for char in "seven":
        s = s.replace(char, '', number_of_numbers[7])

    number_of_numbers[2] = s.count('w')
    for char in "two":
        s = s.replace(char, '', number_of_numbers[2])

    number_of_numbers[0] = s.count('z')
    for char in "zero":
        s = s.replace(char, '', number_of_numbers[0])

    number_of_numbers[4] = s.count('u')
    for char in "four":
        s = s.replace(char, '', number_of_numbers[4])

    number_of_numbers[5] = s.count('v')
    for char in "five":
        s = s.replace(char, '', number_of_numbers[5])

    number_of_numbers[8] = s.count('g')
    for char in "eight":
        s = s.replace(char, '', number_of_numbers[8])

    number_of_numbers[9] = s.count('i')
    for char in "nine":
        s = s.replace(char, '', number_of_numbers[9])

    number_of_numbers[3] = s.count('h')
    for char in "three":
        s = s.replace(char, '', number_of_numbers[3])

    number_of_numbers[1] = s.count('o')
    for char in "one":
        s = s.replace(char, '', number_of_numbers[1])

    for i in range(10):
        answer += str(i) * number_of_numbers[i]

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)
