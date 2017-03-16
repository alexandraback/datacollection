def revenge_of_the_pancakes(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        n_line_per_problem = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            pile = lines[line_number].rstrip('\n')
            n_flip = 0
            first_pancake = pile[0]
            for pancake in pile:
                if pancake != first_pancake:
                    first_pancake = pancake
                    n_flip += 1
            if first_pancake == '-':
                n_flip += 1
            # end of problem logic
            print("Case #{}: {}".format(test_case_number, n_flip))
            line_number += n_line_per_problem

revenge_of_the_pancakes('file.txt')
exit()
