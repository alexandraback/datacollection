def parsing():
    nb_tests = int(raw_input())
    cases = []
    
    for _ in range(nb_tests):
        cases.append([int(a) for a in raw_input().split()])

    return nb_tests, cases

def display(case_number, matrix_result):
    print "Case #" + str(case_number) + ": " + str(len(matrix_result))
    for i in range(len(matrix_result)):
        print ' '.join([str(a) for a in matrix_result[i]])


def solve(case):
    K = case[3]
    J = case[0]
    P = case[1]
    S = case[2]

    result = []

    if K >= max([J * P, J * S, S * P]):
        for i in range(J):
            for j in range(P):
                for k in range(S):
                    result.append([i + 1, j + 1, k + 1])
        return result

    couple_dic = []
    for i in range(0, J + 1):
        couple_dic.append([])
        for j in range(0, P + 1):
            couple_dic[i].append([])
            for k in range(1, S + 1):
                couple_dic[i][j].append(0)
                couple_dic[i][0].append(0)
                couple_dic[0][j].append(0)

    for i in range(1, J + 1):
        for j in range(1, P + 1):
            for k in range(1, S + 1):
                if couple_dic[i][j][0] < K and couple_dic[i][0][k] < K and couple_dic[0][j][k] < K:
                    result.append([i, j, k])
                    couple_dic[i][j][0] += 1
                    couple_dic[i][0][k] += 1
                    couple_dic[0][j][k] += 1

    return result

def main():
    nb_tests, cases = parsing()

    for i in range(nb_tests):
        display(i + 1, solve(cases[i]))

if __name__=='__main__':
    main()
