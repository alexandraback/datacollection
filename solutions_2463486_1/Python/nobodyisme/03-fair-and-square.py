import sys

input_fname = sys.argv[1]
input_f = open(input_fname)

output_fname = sys.argv[2]
output_f = open(output_fname, 'w')


def test_cases(input_f):
    return input_f.readline()


def parse_test_case(input_f):
    _min, _max = [int(x) for x in input_f.readline().split(' ')]
    return (_min, _max)


fns_list = set([1, 4, 9])
_cur_max = [0]
_cur_min_ls_nod = [0]


def process_test_case(test_case):
    _min, _max = test_case
    if _max > _cur_max[0]:
        generate_fns(_cur_max[0] + 1, _max)

    res = 0
    for i in fns_list:
        if i >= _min and i <= _max:
            res += 1
    return res


def num_of_dec(num):
    res = 0
    while num:
        num /= 10
        res += 1
    return res



def generate_fns(_min, _max):

    print "min, max", _min, _max
    min_num_of_dec = num_of_dec(_min) / 2 + 1
    max_num_of_dec = num_of_dec(_max) / 2 + 1

    ls_min_num_of_dec = (min_num_of_dec / 2 or 1) if _cur_min_ls_nod[0] == 0 else _cur_min_ls_nod[0] + 1
    ls_max_num_of_dec = max_num_of_dec / 2 + 1

    print ls_min_num_of_dec, ls_max_num_of_dec
    for cand in xrange(10 ** (ls_min_num_of_dec - 1), 10 ** ls_max_num_of_dec):
        fp = str(cand)
        pal = fp + fp[::-1]
        sq = int(pal) ** 2
        str_sq = str(sq)
        if str_sq == str_sq[::-1]:
            fns_list.add(sq)
            _cur_max[0] = max(sq, _cur_max[0])
        for i in '0123456789':
            pal = fp + i + fp[::-1]
            sq = int(pal) ** 2
            str_sq = str(sq)
            if str_sq == str_sq[::-1]:
                fns_list.add(sq)
                _cur_max[0] = max(sq, _cur_max[0])

    _cur_min_ls_nod[0] = ls_min_num_of_dec

    print sorted(list(fns_list))



for icase in xrange(int(test_cases(input_f))):
    test_case = parse_test_case(input_f)
    # for line in test_case:
    #     print line
    res = process_test_case(test_case)
    output_f.write('Case #{0}: {1}\n'.format(icase + 1, res))


output_f.flush()
output_f.close()
