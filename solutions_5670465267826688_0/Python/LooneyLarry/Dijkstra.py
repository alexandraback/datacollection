# Google Code Jam 2015 Qualifying C.

import sys

t = {}                          # Table of reductions
# Second value is True if negative
for char in list('1ijk'):
    t['1', char] = (char, False)
    t[char, '1'] = (char, False)
    t[char, char] = ('1', True)
t['1', '1'] = ('1', False)
t['i', 'j'] = ('k', False)
t['i', 'k'] = ('j', True)
t['j', 'i'] = ('k', True)
t['j', 'k'] = ('i', False)
t['k', 'i'] = ('j', False)
t['k', 'j'] = ('i', True)

def reduce(char1, char2):
    global negative
    (result, negate) = t[char1, char2]
    if negate:
        negative = not negative
    return result

# To win we need to produce letter from front of list s.
def reduceTo(letter, s):
    while s[0] != letter or negative:
        first = s.pop(0)
        second = s.pop(0)
        s[0:0] = reduce(first, second)
    s.pop(0)                    # Done with target letter

def doCase(file):
    global negative
    negative = False
    repeat = int(file.readline().split()[1])
    s = list(file.readline().strip()) * repeat
    try:
        reduceTo('i', s)
        reduceTo('j', s)
        reduceTo('k', s)
        while len(s) > 0:
            # Eat stuff reducing to nothing
            reduceTo('1', s)
    except IndexError:
        return 'NO'
    return 'NO' if negative else 'YES'

def run():
    file = open(sys.argv[1])
    numCases = int(file.readline())
    for case in range(1, numCases+1):
        answer = doCase(file)
        print 'Case #{0}: {1}'.format(case, answer)
run()
