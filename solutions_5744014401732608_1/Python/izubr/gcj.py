

def form_result(possibility, matrix, case):
    if possibility == "POSSIBLE":
        print "Case #%s: %s" % (case + 1, possibility)
        print matrix.rstrip()
    else:
        print "Case #%s: %s" % (case + 1, possibility)


t = int(raw_input(""))
for case in range(t): 
    b, m = raw_input("").split(" ")
    b, m = int(b), int(m)
    matrix = [[1] * b for i in range(b)]
    for i in range(b):
        for j in range(b):
            if i >= j:
                matrix[i][j] = 0
    in_point = [0] * b
    from_point = [0] * b
    in_point[0] = 1
    cur_sum = 1
    for i in range(1, b):
        in_point[i] = 2 ** (i - 1)
    for i in range(b):
        from_point[i] = in_point[b - 1 - i]
    paths = [[0] * b for i in range(b)]
    for i in range(b):
        for j in range(b):
            if i < j:
                paths[i][j] = in_point[i] * from_point[j]
    if m > in_point[b-1]:
        # print in_point[b-1]
        form_result("IMPOSSIBLE", [], case)
        continue
    bin_digits = bin(m)[2:] + '0'
    bin_digits = '0' * (b - len(bin_digits)) + bin_digits
    # print bin_digits
    all_zeros = True
    for j in range(1, b):
        if bin_digits[j] == '0':
            matrix[0][j] = 0
        else:
            all_zeros = False
    if all_zeros:
        for j in range(1, b):
            matrix[0][j] = 1

    res_matrix = ""
    for i in range(b):
        res = ""
        for j in range(b):
            res += str(matrix[i][j])
        res_matrix += res + "\n"

    form_result("POSSIBLE", res_matrix, case)



    # print in_point
    # print from_point

    # for i in range(b):
    #     res = ""
    #     for j in range(b):
    #         res += str(paths[i][j]) + " "
    #     print res


    # form_result(best_code, best_jam, case)


