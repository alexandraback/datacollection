def round1a_a(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            letters = list(lines[line_number].split()[0])
            result = []
            for letter in letters:
                if len(result) == 0:
                    result.append(letter)
                elif letter >= result[0]:
                    result.insert(0, letter)
                else:
                    result.append(letter)
            # end of problem logic
            print("Case #{}: {}".format(test_case_number, "".join(result)))
            line_number += n_line_per_problem


round1a_a('file.txt')
exit()