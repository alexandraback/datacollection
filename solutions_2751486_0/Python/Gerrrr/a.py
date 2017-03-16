from string import ascii_lowercase

consonants = [x for x in ascii_lowercase if x not in "aeiou"]


def suffixes(s):
    while s:
        for pref in all_prefixes(s):
            yield pref, calc(pref)
        s = s[1:]


def all_prefixes(s):
    while s:
        yield s
        s = s[:-1]


def calc(s):
    counters = [0]
    counter = 0
    for x in s:
        if x in consonants:
            counter += 1
        else:
            counters.append(counter)
            counter = 0
    counters.append(counter)
    return max(counters)


def solve_case(case):
    s, n = case
    counter = 0
    for x, num in suffixes(s):
        if num >= n:
            counter += 1
    return counter


input_file = "input.txt"
input_file = "/Users/gerrrr/Downloads/A-small-attempt0 (2).in"
with open(input_file) as f:
    f.readline()
    cases = [map(lambda x: x.strip(), x.split(' '))
             for x in f.readlines()]
    cases = [(x, int(y)) for x, y in cases]


#print solve_case(cases[1])
for i, r in enumerate(map(solve_case, cases)):
    print 'Case #%s: %s' % (i + 1, r)
