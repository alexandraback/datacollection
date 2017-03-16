import sys



def generate_headers(char_typed, prob_i):
    """
    Generates a list of possibles give the input [p1, p2, p3, p4.... pn]
    Note the p are probably of correctly typing!
    """
    case_headers = {}
    bin_string = []
    done_string = []
    b_i = 0
    while b_i < char_typed:
        bin_string.append('0')
        done_string.append('1')
        b_i += 1

    done = False
    while not done:
        prob = 1
        b_j = 0
        while b_j < char_typed:
            # 1 denotes that it is an error!

            if bin_string[b_j] == '1':
                prob *= 1 - prob_i[b_j]
            else:
                prob *= prob_i[b_j]
            b_j += 1

        case_headers["".join(bin_string)] = prob
        if bin_string == done_string:
            done = True
        binary_add(bin_string)

    return case_headers


def binary_add(bin_string):
    done = False
    pos = len(bin_string) - 1
    while not done:
        cur = bin_string[pos]
        if pos < 0:
            done = True
        elif cur == '0':
            bin_string[pos] = '1'
            done = True
        else:
            bin_string[pos] = '0'
            pos -= 1

    return bin_string

def calc_exp_given_num_backspaces_equal_zero(headers, char_typed, char_total):

    exp_av = 0

    for key in headers.keys():
        exp = char_total - char_typed + 1
        # There is a mistake!
        if '1' in key:
            exp += char_total + 1

        exp_av += exp * headers[key]

    return exp_av


def calc_exp_given_num_backspaces_greater_zero(num_backspaces, headers, char_typed, char_total):

    if num_backspaces == char_typed:
        # in this case the amount in constant!

        return char_total - char_typed + 1 + 2*num_backspaces

    else:

        exp_av = 0

        for key in headers.keys():
            exp = char_total - char_typed + 1 + 2*num_backspaces
            # There is a mistake!
            if '1' in key[0:-1*num_backspaces]:
                exp += char_total + 1

            exp_av += exp * headers[key]

        return exp_av



in_file = open(sys.argv[1])

num_test_cases = int(in_file.readline().strip())

for i in range(num_test_cases):
    first_line = in_file.readline().strip().split(' ')
    second_line = in_file.readline().strip().split(' ')

    char_typed = int(first_line[0])
    char_total = int(first_line[1])

    prob_of_correct = [float(x) for x in second_line]

    headers = generate_headers(char_typed, prob_of_correct)

    exp_list = []

    # if you just press enter it's the same num every time
    exp_list.append(char_total + 2)

    exp_list.append(calc_exp_given_num_backspaces_equal_zero(headers, char_typed, char_total))

    for num_back in range(1, char_typed + 1):
        exp_list.append(calc_exp_given_num_backspaces_greater_zero(num_back, headers, char_typed, char_total))

    print "Case #%s: %s" % (i+1,min(exp_list))





