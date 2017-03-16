def round1a_b(path):
    with open(path, mode='r') as file:
        lines = file.readlines()
        test_case_number = 0
        line_number = 1
        while test_case_number < int(lines[0]):
            test_case_number += 1
            # variables for this problem
            n = int(lines[line_number].split()[0])
            result = []
            matrice = []
            for i in range(2*n - 1):
                matrice.append(lines[line_number + i + 1].split())
            matrice_flat = [int(item) for sublist in matrice for item in sublist]

            for i in matrice_flat:
                count = 0
                for j in matrice_flat:
                    if i == j:
                        count += 1
                if count % 2 == 1:
                    result.append(i)
                matrice_flat = remove_values_from_list(matrice_flat, i)
            result.sort()
            # end of problem logic
            my_result = ""
            for item in result:
                my_result += str(item) + " "
            print("Case #{}: {}".format(test_case_number, my_result))
            line_number += 2*n


def remove_values_from_list(my_list, x):
    return [value for value in my_list if value != x]


round1a_b('file.txt')
exit()