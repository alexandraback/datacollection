import math


def get_divisor(num):
    if num == 2:
        return -1
    if num % 2 == 0:
        return 2
    sqr = min(int(math.sqrt(num)) + 1, 100)
    for divisor in range(3, sqr, 2):
        if num % divisor == 0:
            return divisor
    return -1


def get_coin_jams(cur_str, len_left, amount_left):
    if amount_left == 0:
        return [], 0
    if len_left != 0:
        opts_1, new_amt_left = get_coin_jams(cur_str + '0', len_left - 1, amount_left)
        opts_2, new_amt_left = get_coin_jams(cur_str + '1', len_left - 1, new_amt_left)
        return opts_1 + opts_2, new_amt_left
    cur_str += '1'
    divs = [str(get_divisor(int(cur_str, base))) for base in range(2, 11)]
    if '-1' in divs:
        return [], amount_left
    else:
        return [[cur_str, divs]], amount_left - 1

file = open('C-large.in', 'r')
out_file = open('output_file.txt', 'w')
amount = file.readline()
for i in range(int(amount)):
    args = file.readline().strip().split()
    n, j = int(args[0]), int(args[1])
    out_file.write('Case #' + str(i + 1) + ":\n")
    output = get_coin_jams('1', n - 2, j)[0]
    for coin_jam in output:
        out_file.write(coin_jam[0] + ' ' + ' '.join(coin_jam[1]) + '\n')
file.close()
out_file.close()
