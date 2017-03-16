__author__ = 'sean'

# io_type = 'test'
# io_type = 'small'
io_type = 'large'

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

"""
values = {}

def compute(n):
    n_str = str(n)
    n_rev = int(n_str[::-1])
    option_1 = values[n-1]
    if not n_str[-1] == '0' and n_rev in values:
        option_2 = values[n_rev]
    else:
        option_2 = float("inf")
    total = 1 + min(option_1, option_2)
    values[n] = total

values[1] = 1
for i in range(2, 100000000000000):
    compute(i)

def slow_solve(n):
    return values[n]
"""

def solve(n):
    if n <= 10:
        return n
    else:
        current = 10
        total = 10
        num_digits = 2

        while True:
            if n >= 10*current:
                direct_to_n = current*10-current
                best_flip_str = ('1' + '0'*((num_digits-1)//2) + '9'*(num_digits//2))
                initial_flip = int(best_flip_str)
                end_of_flip = int(best_flip_str[::-1])

                with_skip = (10*current - end_of_flip) + (initial_flip - current) + 1

                current *= 10
                total += min(direct_to_n, with_skip)
                num_digits += 1
            else:
                direct_to_n = n - current
                n_str = str(n)

                last_characters = n_str[0:(num_digits//2)]
                best_flip_str = ('1' + '0'*((num_digits-1)//2) + last_characters[::-1])

                initial_flip = int(best_flip_str)
                end_of_flip = int(best_flip_str[::-1])

                if end_of_flip <= n:
                    with_skip = (n - end_of_flip) + (initial_flip - current) + 1
                else:
                    with_skip = float("inf")

                other_n_str = str(n-1)
                other_last_characters = other_n_str[0:(num_digits//2)]
                other_flip_str = ('1' + '0'*((num_digits-1)//2) + other_last_characters[::-1])

                other_initial = int(other_flip_str)
                other_end = int(other_flip_str[::-1])

                if other_end <= n:
                    with_skip = min(with_skip, (n - other_end) + (other_initial - current) + 1)

                total += min(direct_to_n, with_skip)
                return total


for case in range(numbCases):
    _n = int(next(it).rstrip())

    line = "Case #{0}: {1}\n".format(str(case+1), str(solve(_n)))
    output += line


with open(OUT_FILE, 'w') as fileOut:
    fileOut.write(output)