def work(case_vars):
    r, c, m = case_vars
    imp = "Impossible"
    b = [['*' for _ in range(c)] for _ in range(r)]
    free = r*c - m

    if free < 1:
        return imp

    if free == 1:
        b[0][0] = 'c'
        return "\n".join(["".join(i) for i in b])

    if r == 1:
        for i in range(free):
            b[0][i] = '.'
        b[0][0] = 'c'
        return "\n".join(["".join(i) for i in b])

    if c == 1:
        for i in range(free):
            b[i][0] = '.'
        b[0][0] = 'c'
        return "\n".join(["".join(i) for i in b])

    if free < 4:
        return imp

    if r == 2 or c == 2:
        if free % 2 == 1:
            return imp
        elif r == 2:
            for i in range(free/2):
                b[0][i] = '.'
                b[1][i] = '.'
        else:
            for i in range(free/2):
                b[i][0] = '.'
                b[i][1] = '.'
        b[0][0] = 'c'
        return "\n".join(["".join(i) for i in b])
    #
    # Under here r >= 3, c >= 3 , free >= 4
    #
    if free < 8 and free % 2 == 1:
        return imp

    for i in range(2):
        for j in range(2):
            b[i][j] = '.'
            free -= 1

    ri = 2
    ci = 2
    while free >= 4 and not (ri >= r and ci >= c):
        if ri < r:
            b[ri][0] = '.'
            b[ri][1] = '.'
            free -= 2
            ri += 1
        if ci < c:
            b[0][ci] = '.'
            b[1][ci] = '.'
            free -= 2
            ci += 1

    if 4 > free > 1:
        if ri < r:
            b[ri][0] = '.'
            b[ri][1] = '.'
            free -= 2
        elif ci < c:
            b[0][ci] = '.'
            b[1][ci] = '.'
            free -= 2

    if free == 1:
        b[2][2] = '.'
        free -= 1

    #free >= 4
    if free > 0:
        for i in range(2, r):
            for j in range(2, c):
                b[i][j] = '.'
                free -= 1
                if free == 0:
                    break
            if free == 0:
                break

    b[0][0] = 'c'
    s = "\n".join(["".join(i) for i in b])
    # print s
    # print "\n\n"
    return s


def get_cases(f):
    #read num of cases
    cases = int(f.readline())
    for case in range(cases):
        #read r, c, m
        r, c, m = [int(i) for i in f.readline().split()]

        yield case+1, r, c, m


def main():
    flag = 2

    input_name = "test.in" if flag == 0 else "C-small-attempt4.in" if flag == 1 else "C-large.in"
    output_name = input_name[:-2] + "out"
    print input_name
    print output_name

    with open(input_name, 'rb') as in_file,  open(output_name, 'w') as out_file:
        for case_vars in get_cases(in_file):
            case = case_vars[0]
            print case
            c = work(case_vars[1:])
            out_file.write("Case #%d:\n%s" % (case, c) + "\n")


main()
