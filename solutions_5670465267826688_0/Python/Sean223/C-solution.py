__author__ = 'sean'

# io_type = 'test'
io_type = 'small'
# io_type = 'large'

if io_type == 'large':
    IN_FILE = 'C-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'C-small.in'
    OUT_FILE = 'small_out.txt'

else:
    IN_FILE = 'test_input.txt'
    OUT_FILE = 'test_output.txt'


with open(IN_FILE, 'r') as fileIn:
    fileLines = fileIn.readlines()

it = iter(fileLines)
numbCases = int(next(it))
output = ""

table = {('1', '1'): '1', ('1', 'i'): 'i', ('1', 'j'): 'j', ('1', 'k'): 'k',
         ('i', '1'): 'i', ('i', 'i'): '-1', ('i', 'j'): 'k', ('i', 'k'): '-j',
         ('j', '1'): 'j', ('j', 'i'): '-k', ('j', 'j'): '-1', ('j', 'k'): 'i',
         ('k', '1'): 'k', ('k', 'i'): 'j', ('k', 'j'): '-i', ('k', 'k'): '-1'}


def solve(expression):
    first_i = None
    first_k = None
    total = '1'
    positive = True

    for i in range(len(expression)):
        total = table[(total, expression[i])]
        if total[0] == '-':
            total = total[1]
            positive = not positive
        if total == 'i' and positive and first_i is None:
            first_i = i

    if total == '1' and not positive and first_i is not None:
        back_total = '1'
        back_positive = True
        for i in reversed(range(len(expression))):
            back_total = table[(expression[i], back_total)]
            if back_total[0] == '-':
                back_total = back_total[1]
                back_positive = not back_positive
            if back_total == 'k' and back_positive and first_k is None:
                first_k = i
                break

    if first_k is not None and first_k > first_i+1:
        return True

    return False

for case in range(numbCases):
    first_line = next(it).split(' ')
    _l, x = int(first_line[0]), int(first_line[1])

    second_line = str(next(it).strip())
    string = second_line * x

    if solve(string):
        answer = 'YES'
    else:
        answer = 'NO'

    output += "Case #{0}: {1}\n".format(str(case+1), str(answer))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)