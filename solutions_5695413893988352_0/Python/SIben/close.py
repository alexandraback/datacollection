def parsing():
    nb_tests = int(raw_input())
    cases = []
    
    for _ in range(nb_tests):
        cases.append(raw_input())

    return nb_tests, cases

def display(case_number, res):
    resultC = res[0]
    resultJ = res[1]
    print "Case #" + str(case_number) + ": " + str(resultC) + " " + str(resultJ)


def is_possible(score, val):

    s_val = str(val)
    if len(score) > len(s_val):
        s_val = (len(score) - len(s_val)) * '0' + s_val

    for idx in range(len(s_val)):
        if score[idx] != s_val[idx] and score[idx] != '?':
            return False

    return True


def solve(score_c, score_j):
    # Bruteforcing the small dataset

    val_c = []
    val_j = []

    for i in range(10 ** len(score_c)):
        if is_possible(score_c, i):
            val_c.append(i)
        if is_possible(score_j, i):
            val_j.append(i)

    min_diff = min([abs(a - b) for a in val_c for b in val_j])

    possible_couples = [(a, b) for a in val_c for b in val_j if abs(a - b) == min_diff]

    minim = min([x[0] for x in possible_couples])
    possible_couples = [x for x in possible_couples if x[0] == minim]

    minim = min([x[1] for x in possible_couples])
    possible_couples = [x for x in possible_couples if x[1] == minim]

    result = []
    for i in range(2):
        tmp = str(possible_couples[0][i])
        tmp = (len(score_c) - len(tmp)) * '0' + tmp
        result.append(tmp)
    return result

def main():
    nb_tests, cases = parsing()

    for i in range(nb_tests):
        display(i + 1, solve(cases[i].split()[0], cases[i].split()[1]))

if __name__=='__main__':
    main()
