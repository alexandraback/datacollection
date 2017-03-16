def parsing():
    nb_tests = int(raw_input())
    cases = []
    
    for _ in range(nb_tests):
        cases.append([int(a) for a in raw_input().split()])

    return nb_tests, cases

def display(case_number, result):
    if result == []:
        print "Case #" + str(case_number) + ": " + "IMPOSSIBLE"
        return
    
    print "Case #" + str(case_number) + ": " + "POSSIBLE"
    for i in range(len(result)):
        print result[i]

def solve(case):
    nb_buildings = case[0]
    nb_ways = case[1]

    if nb_ways > (nb_buildings - 1) * nb_buildings / 2 - (nb_buildings - 2):
        return []

    bridges_matrix = []
    for i in range(nb_buildings):
        bridges_matrix.append([0 for _ in range(nb_buildings)])

    crafted_ways = 0

    while nb_ways != crafted_ways:
        if crafted_ways == 0:
            crafted_ways += 1
            bridges_matrix[0][nb_buildings - 1] = 1
            continue

        if crafted_ways < nb_buildings - 1:
            bridges_matrix[0][crafted_ways] = 1
            bridges_matrix[crafted_ways][nb_buildings - 1] = 1
            crafted_ways += 1
            continue

        for i in range(1, nb_buildings - 1):
            for j in range(i + 1, nb_buildings - 1):
                if bridges_matrix[i][j] == 0:
                    bridges_matrix[i][j] = 1
                    crafted_ways += 1
                    break
            else:
                continue
            break

    return_matrix = [''.join([str(a) for a in elem]) for elem in bridges_matrix]
    return return_matrix

def main():
    nb_tests, cases = parsing()

    for i in range(nb_tests):
        display(i + 1, solve(cases[i]))

if __name__=='__main__':
    main()
