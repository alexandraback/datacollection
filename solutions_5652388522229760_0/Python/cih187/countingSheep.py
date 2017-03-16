def problem_name(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            N =int(lines[line_number].split(' ')[0])
            numbers = ""
            Ni = 0
            i = 1
            if N != 0:
                while len(numbers) != 10:
                    Ni = i * N
                    for letter in str(Ni):
                        if numbers.find(letter) == -1:
                            numbers += letter
                    i += 1
                print("Case #{}: {}".format(test_case_number, Ni))
            else:
                print("Case #{}: INSOMNIA".format(test_case_number))
            # end of problem logic

            line_number += n_line_per_problem


problem_name('file.txt')
exit()
