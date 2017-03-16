def round1a_c(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 2
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            n = int(lines[line_number].split()[0])
            bffs = [int(i) for i in lines[line_number + 1].strip('\n').split()]
            result = 0
            for i in range(n//2):
                essai = [elem if someone_loves_him(bffs, i + 1) else 0 for i, elem in enumerate(bffs)]
                bffs = essai[:]
            count = 0
            for i, elem in enumerate(essai):
                if elem != 0:
                    result += 1
                if essai[elem - 1] == i + 1:
                    count += 1

            result += count // 2

            # end of problem logic
            print("Case #{}: {}".format(test_case_number, result))
            line_number += n_line_per_problem


def someone_loves_him(my_list, elem):
    for i in my_list:
        if elem == i:
            return True
    return False

round1a_c('file.txt')
exit()