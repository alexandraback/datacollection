import sys
import functools


a_in = 'ejp mysljylc kd kxveddknmc re jsicpdrysi'
a_out = 'our language is impossible to understand'

b_in = 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'
b_out = 'there are twenty six factorial possibilities'

c_in = 'de kr kd eoya kw aej tysr re ujdr lkgc jv'
c_out = 'so it is okay if you want to just give up'

mapping = {'a': 'y', 'o': 'e', 'z': 'q'}

for in_str, out_str in [(a_in, a_out), (b_in, b_out), (c_in, c_out)]:
    stripped_in = in_str.replace(' ', '')
    stripped_out = out_str.replace(' ', '')
    
    for in_char, out_char in zip(stripped_in, stripped_out):
        mapping[in_char] = out_char
  
all_letters = set()
for i in xrange(ord('a'), ord('z') + 1):
    all_letters.add(chr(i))

extra_in = (all_letters - set(mapping.keys())).pop()

extra_out = (all_letters - set(mapping.values())).pop()

mapping[extra_in] = extra_out

def read_case(line):
    return line.strip()


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines.next())))

    return cases

def solve(line):
    out = ''
    for i in line:
        if i == ' ':
            out += i
        else:
            out += mapping[i]
    return out

if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
