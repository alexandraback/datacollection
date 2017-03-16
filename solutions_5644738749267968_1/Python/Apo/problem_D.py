from bisect import bisect


def war_score(b1, b2):
    score = 0
    for item in b1:
        if item > b2[-1]:
            del b2[0]
            score += 1
        else:
            i = bisect(b2, item)
            del b2[i]
    return score


def deceitful_war_score(b1, b2):
    l = len(b1)
    score = [[0 for _ in range(l)] for _ in range(l)]

    for i in range(l):
        if b1[i] > b2[0]:
            score[0][i] = 1
        if b1[0] > b2[i]:
            score[i][0] = 1

    for i in range(1, l):
        for j in range(1, l):
            a = 0
            if b1[j] > b2[i]:
                a = 1
            score[i][j] = max(score[i][j-1], score[i-1][j], score[i-1][j-1] + a)

    return score[-1][-1]


def work(case_vars):
    n, b1, b2 = case_vars
    b1.sort()
    b2.sort()

    return deceitful_war_score(b1, list(b2)), war_score(b1, b2)


def get_cases(f):
    #read num of cases
    cases = int(f.readline())
    for case in range(cases):
        n = int(f.readline())
        #read r, c, m
        b1 = [float(i) for i in f.readline().split()]
        b2 = [float(i) for i in f.readline().split()]

        yield case+1, n, b1, b2


def main():
    flag = 2

    input_name = "test.in" if flag == 0 else "D-small-attempt0.in" if flag == 1 else "D-large-practice.in"
    output_name = input_name[:-2] + "out"
    print input_name
    print output_name

    with open(input_name, 'rb') as in_file,  open(output_name, 'w') as out_file:
        for case_vars in get_cases(in_file):
            case = case_vars[0]
            dw, w = work(case_vars[1:])
            out_file.write("Case #%d: %d %d\n" % (case, dw, w))


main()
