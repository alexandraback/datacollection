def parsing():
    nb_tests = int(raw_input())
    cases = []
    
    for _ in range(nb_tests):
        cases.append(raw_input())

    return nb_tests, cases

def display(case_number, result):
    print "Case #" + str(case_number) + ": " + ''.join(sorted([str(i) for i in result]))


def solve(string):
    retval = []

    count_8 = string.count('G')
    count_6 = string.count('X')
    count_4 = string.count('U')
    count_2 = string.count('W')
    count_0 = string.count('Z')

    for i in 'ZERO' * count_0 + 'TWO' * count_2 + 'EIGHT' * count_8 + 'SIX' * count_6 + 'FOUR' * count_4:
        string = string.replace(i, '', 1)

    count_7 = string.count('S')
    count_5 = string.count('F')
    count_3 = string.count('H')

    for i in 'SEVEN' * count_7 + 'FIVE' * count_5 + 'THREE' * count_3:
        string = string.replace(i, '', 1)

    count_9 = string.count('I')
    count_1 = string.count('O')

    retval += [0] * count_0
    retval += [1] * count_1
    retval += [2] * count_2
    retval += [3] * count_3
    retval += [4] * count_4
    retval += [5] * count_5
    retval += [6] * count_6
    retval += [7] * count_7
    retval += [8] * count_8
    retval += [9] * count_9

    return retval

def main():
    nb_tests, cases = parsing()
    
    for i in range(nb_tests):
        display(i + 1, solve(cases[i]))

if __name__=='__main__':
    main()
