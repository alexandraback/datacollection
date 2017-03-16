def fractiles(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            data = lines[line_number].split(' ')
            k = int(data[0])
            c = int(data[1])
            s = int(data[2])

            tiles_to_check = [i+1 for i in range(k)]


            # end of problem logic
            print("Case #{}: ".format(test_case_number), end='')
            for x in tiles_to_check:
                print(x, end=' ')
            print()
            line_number += n_line_per_problem


fractiles('file.txt')
exit()