import math


def coin_jam(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 1
        while test_case_number < int(lines[0]):
            print("Case #{}: {}".format(test_case_number, '\n'))
            test_case_number += 1
            # variables for this problem
            data = lines[line_number].split(' ')
            N = int(data[0])
            J = int(data[1])
            number = str(bin(2**(N-1)+1))[2::]
            jam_coin_list = []
            while len(jam_coin_list) < J:
                divisor_list = []
                is_jam_coin = True
                for i in range(2, 11):
                    num_base_i = int(number, i)
                    divisor_list.append(is_prime(num_base_i))
                    if divisor_list[i-2] == 0:
                        is_jam_coin = False
                        break
                if is_jam_coin:
                    print("{}".format(number), end= ' ')
                    for x in divisor_list:
                        print(x, end=' ')
                    print()
                    jam_coin_list.append(number)
                temp = bin(2)[2::]
                number = bin(int(temp,2) + int(number,2))[2::]


def is_prime(n):
    n = abs(int(n))
    if n == 0:
        return 1
    elif n == 1:
        return 1
    elif n % 2 == 0 and n > 2:
        return 2
    elif n % 3 == 0 and n > 3:
        return 3
    elif n % 5 == 0 and n > 5:
        return 5
    elif n % 7 == 0 and n > 7:
        return 7
    elif n % 11 == 0 and n > 11:
        return 11
    elif n % 13 == 0 and n > 13:
        return 13
    elif n % 17 == 0 and n > 17:
        return 17
    elif n % 19 == 0 and n > 19:
        return 19
    elif n % 23 == 0 and n > 23:
        return 23
    elif n % 29 == 0 and n > 29:
        return 29
    return 0


coin_jam('file.txt')
exit()