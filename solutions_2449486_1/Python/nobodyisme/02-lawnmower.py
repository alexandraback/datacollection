import sys

input_fname = sys.argv[1]
input_f = open(input_fname)

output_fname = sys.argv[2]
output_f = open(output_fname, 'w')


def test_cases(input_f):
    return input_f.readline()


def parse_test_case(input_f):
    rows, cols = [int(x) for x in input_f.readline().split(' ')]
    test_case = []
    for i in xrange(rows):
        row = []
        for x in input_f.readline().strip().split():
            row.append(int(x))
        test_case.append(row)
    return test_case


def process_test_case(test_case):

    row_check_set = set()
    idxes_set = set(range(len(test_case[0])))
    for i, row in enumerate(test_case):
        row_max_idxs = []
        row_max_val = 0

        for j, val in enumerate(row):
            if val > row_max_val:
                row_max_val = val
                row_max_idxs = [j]
            elif val == row_max_val:
                row_max_idxs.append(j)

        for idx in idxes_set - set(row_max_idxs):
            row_check_set.add((i, idx))

    col_check_set = set()
    idxes_set = set(range(len(test_case)))
    for j, val in enumerate(test_case[0]):
        col_max_idxs = []
        col_max_val = 0

        for i, row in enumerate(test_case):

            # !
            val = row[j]

            if val > col_max_val:
                col_max_val = val
                col_max_idxs = [i]
            elif val == col_max_val:
                col_max_idxs.append(i)

        for idx in idxes_set - set(col_max_idxs):
            col_check_set.add((idx, j))

    check_set = col_check_set & row_check_set
    return 'NO' if check_set else 'YES'



for icase in xrange(int(test_cases(input_f))):
    test_case = parse_test_case(input_f)
    # for line in test_case:
    #     print line
    res = process_test_case(test_case)
    output_f.write('Case #{0}: {1}\n'.format(icase + 1, res))


output_f.flush()
output_f.close()
