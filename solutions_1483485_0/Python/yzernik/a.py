import sys
import string

def solve_a(infile, outfile):
    f = open(infile, 'r')
    r = open(outfile, 'w')
    num_cases = int(f.readline())
    reverse_mapping = get_reverse_mapping()
    for case_index in range(num_cases):
        line = str(f.readline()[:-1])
        r.write("Case #" + str(case_index+1) + ": " + translate_text(line, reverse_mapping) + "\n")

def translate_text(text, reverse_mapping):
    result = ''
    for c in text:
        result += translate_char(c, reverse_mapping)
    return result

def translate_char(c, reverse_mapping):
    if c in reverse_mapping:
        return reverse_mapping[c]
    else:
        return c

def get_reverse_mapping():
    reverse_mapping = {}
    example_inputs = ['ejp mysljylc kd kxveddknmc re jsicpdrysi',
                      'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
                      'de kr kd eoya kw aej tysr re ujdr lkgc jv']
    example_outputs = ['our language is impossible to understand',
                       'there are twenty six factorial possibilities',
                       'so it is okay if you want to just give up']
    for pair in zip(example_inputs, example_outputs):
        for i in range(len(pair[0])):
            reverse_mapping[pair[0][i]] = pair[1][i]
    reverse_mapping['z'] = 'q'
    reverse_mapping['q'] = 'z'
    return reverse_mapping


if __name__ == '__main__':
    infile = str(sys.argv[1])
    outfile = str(sys.argv[2])
    solve_a(infile, outfile)
