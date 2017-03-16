import sys

MAX_CIRCLES = 999999999
RES_FLOAT_STR_FORMAT = "{:.6f}"


VOWELS = { 'a', 'i', 'u', 'e', 'o' }

def is_consonant(char):
    return char not in VOWELS

def add_substrings(set, string, keep_range):
    for i in range(0, keep_range[0]+1):
        for j in range(len(string)-1, keep_range[1]-1, -1):
            set.add((i,j))

def find_cons_ranges(string, range_min_len):
    ranges = []
    ind_start = -1
    ind_end = -1
    ind = 0
    #import pdb; pdb.set_trace()
    while ind < len(string):
        if is_consonant(string[ind]):
            ind_start = ind
            ind += 1
            while ind < len(string) and is_consonant(string[ind]):
                ind += 1
            #went out, current string[ind] is \0 or a vowel
            ind_end = ind

            #we have a range
            if ind_end - ind_start >= range_min_len:
                for i in range(ind_start, ind_end - range_min_len + 1):
                    ranges.append((i, i+range_min_len-1))
        else: ind += 1
    return ranges

def n_range(string, n):
    consonant_ranges = find_cons_ranges(string, n)
    res_set = set()
    for range in consonant_ranges:
        add_substrings(res_set, string, range)
    return len(res_set)


def main(input_file_name, output_file_name):
    input_file = open(input_file_name, 'rU')
    output_file = open(output_file_name, 'w')
    for case in range(int(input_file.readline())):
        string, n_str = [x for x in input_file.readline().split()]
        res_n_range = n_range(string, int(n_str))
        output_file.write('Case #' + str(case+1) + ': ' + str(res_n_range) + '\n')
    input_file.close()
    output_file.close()


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
