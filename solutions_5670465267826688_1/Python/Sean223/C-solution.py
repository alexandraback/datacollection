__author__ = 'sean'

# io_type = 'test'
# io_type = 'small'
io_type = 'large'

if io_type == 'large':
    IN_FILE = 'C-large.in'
    OUT_FILE = 'large_out.txt'

elif io_type == 'small':
    IN_FILE = 'C-small.in'
    OUT_FILE = 'small_out_2.txt'

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


def power(quaternion, exponent):
    if quaternion == '1':
        return '1'
    
    elif quaternion == '-1' and exponent % 2 == 0:
        return '1'
    elif quaternion == '-1':
        return '-1'
    
    elif quaternion == 'i' and exponent % 4 == 1:
        return 'i'
    elif quaternion == 'i' and exponent % 4 == 2:
        return '-1'
    elif quaternion == 'i' and exponent % 4 == 3:
        return '-i'
    elif quaternion == 'i':
        return '1'
    
    elif quaternion == '-i' and exponent % 4 == 1:
        return '-i'
    elif quaternion == '-i' and exponent % 4 == 2:
        return '-1'
    elif quaternion == '-i' and exponent % 4 == 3:
        return 'i'
    elif quaternion == '-i':
        return '1'
    
    elif quaternion == 'j' and exponent % 4 == 1:
        return 'j'
    elif quaternion == 'j' and exponent % 4 == 2:
        return '-1'
    elif quaternion == 'j' and exponent % 4 == 3:
        return '-j'
    elif quaternion == 'j':
        return '1'
    
    elif quaternion == '-j' and exponent % 4 == 1:
        return '-j'
    elif quaternion == '-j' and exponent % 4 == 2:
        return '-1'
    elif quaternion == '-j' and exponent % 4 == 3:
        return 'j'
    elif quaternion == '-j':
        return '1'
    
    elif quaternion == 'k' and exponent % 4 == 1:
        return 'k'
    elif quaternion == 'k' and exponent % 4 == 2:
        return '-1'
    elif quaternion == 'k' and exponent % 4 == 3:
        return '-k'
    elif quaternion == 'k':
        return '1'
    
    elif quaternion == '-k' and exponent % 4 == 1:
        return '-k'
    elif quaternion == '-k' and exponent % 4 == 2:
        return '-1'
    elif quaternion == '-k' and exponent % 4 == 3:
        return 'k'
    elif quaternion == '-k':
        return '1'


def solve(expression, exponent):
    first_appearance = {}
    last_appearance = {}
    total = '1'
    positive = True

    for i in range(len(expression)):
        total = table[(total, expression[i])]
        if total[0] == '-':
            total = total[1]
            positive = not positive
        if (total, positive) not in first_appearance:
            first_appearance[(total, positive)] = i

    back_total = '1'
    back_positive = True
    for j in reversed(range(len(expression))):
        back_total = table[(expression[j], back_total)]
        if back_total[0] == '-':
            back_total = back_total[1]
            back_positive = not back_positive
        if (back_total, back_positive) not in last_appearance:
            last_appearance[(back_total, back_positive)] = j

    if positive:
        overall_total = power(total, exponent)
    else:
        overall_total = power('-' + total, exponent)

    if not overall_total == '-1':
        return False

    first_i = 100000000000000000000
    last_k = -1

    if ('i', True) in first_appearance:
        first_i = first_appearance[('i', True)]
    else:
        for quaternion, sign in [('1', True), ('1', False), ('i', True), ('i', False), ('j', True),
                                 ('j', False), ('k', True), ('k', False)]:
            if (quaternion, sign) not in first_appearance:
                continue
            earliest_i = first_appearance[(quaternion, sign)]

            current_value = quaternion
            current_positive = sign
            for i in range(1, min(exponent, 4)+1):
                current_value = table[(total, current_value)]
                if current_value[0] == '-':
                    current_value = current_value[1]
                    current_positive = not current_positive
                if not positive:
                    current_positive = not current_positive
                if current_value == 'i' and current_positive:
                    first_i = min(first_i, i*len(expression) + earliest_i + 1)

    if ('k', True) in last_appearance:
        last_k = last_appearance[('k', True)] + (exponent-1) * len(expression)
    else:
        for quaternion, sign in [('1', True), ('1', False), ('i', True), ('i', False), ('j', True),
                                 ('j', False), ('k', True), ('k', False)]:
            if (quaternion, sign) not in last_appearance:
                continue
            latest_i = last_appearance[(quaternion, sign)]

            current_value = quaternion
            current_positive = sign
            for i in range(1, min(exponent, 4)+1):
                current_value = table[(current_value, total)]
                if current_value[0] == '-':
                    current_value = current_value[1]
                    current_positive = not current_positive
                if not back_positive:
                    current_positive = not current_positive
                if current_value == 'k' and current_positive:
                    last_k = max(last_k, (exponent - i - 1)*len(expression) + latest_i + 1)

    if first_i < 1000000000000000000 and last_k > -1 and first_i < last_k:
        return True

    return False

for case in range(numbCases):
    first_line = next(it).split(' ')
    _l, x = int(first_line[0]), int(first_line[1])

    second_line = str(next(it).strip())
    string = second_line

    if solve(string, x):
        answer = 'YES'
    else:
        answer = 'NO'

    line = "Case #{0}: {1}\n".format(str(case+1), str(answer))
    output += line
    print("finished case {0}".format(case+1))


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)