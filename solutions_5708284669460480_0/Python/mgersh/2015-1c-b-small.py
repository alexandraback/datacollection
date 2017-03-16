import string
import math
import itertools

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))


def do_calc(i):
    params = map(int, string.split(string.strip(testcase.readline())))
    k = params[0]
    l = params[1]
    s = params[2]
    kbd = string.strip(testcase.readline())
    kbd = ''.join(sorted(kbd))
    word = string.strip(testcase.readline())
    all_seq = itertools.product(kbd, repeat=s)
    all_strings = []
    for seq in all_seq:
        new_string = ''.join(seq)
        all_strings.append(new_string)
    max_words = 0
    total_words = 0
    num_strings = len(all_strings)
    for strng in all_strings:
        num_words = 0
        for idx, let in enumerate(strng):
            if let == word[0]:
                match = True
                for idxb, letter in enumerate(word):
                    if idx+idxb>=len(strng) or letter != strng[idx+idxb]:
                        match = False
                if match:
                    num_words += 1
        if num_words > max_words:
            max_words = num_words
        total_words += num_words
    if max_words == 0:
        return 0.0
    else:
        return max_words - float(total_words)/num_strings
                        

for i in xrange(1, num_cases+1):
    res = do_calc(i)
    print "Case #"+str(i)+": "+str(res)
